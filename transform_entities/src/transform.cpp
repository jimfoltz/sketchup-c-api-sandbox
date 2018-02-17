#include <cassert>

#include <SketchUpAPI/sketchup.h>
#include <iostream>
#include <vector>
#include "utilities/sketchup_error_string.h"

std::vector<SUEntityRef> get_edges(SUEntitiesRef entities)
{
    size_t amount{ 0 };
    std::vector<SUEntityRef> ents{};
    SUEntitiesGetNumEdges(entities, false, &amount);
    size_t count{ 0 };
    std::vector<SUEdgeRef> edges(amount);
    SUEntitiesGetEdges(entities, false, amount, &edges[0], &count);
    for (auto& edge : edges) {
        ents.push_back(SUEdgeToEntity(edge));
    }
    return ents;
}

int main()
{
    // Always initialize the API before using it
    SUInitialize();
    // Create an empty model
    SUModelRef model = SU_INVALID;
    SUResult res = SUModelCreate(&model);
    // It's best to always check the return code from each SU function call.
    // Only showing this check once to keep this example short.
    if (res != SU_ERROR_NONE)
        return 1;
    // Get the entity container of the model
    SUEntitiesRef entities = SU_INVALID;
    SUModelGetEntities(model, &entities);
    // Create a loop input describing the vertex ordering for a face's outer loop
    SULoopInputRef outer_loop = SU_INVALID;
    SULoopInputCreate(&outer_loop);
    for (size_t i = 0; i < 4; ++i)
    {
        SULoopInputAddVertexIndex(outer_loop, i);
    }
    // Create the face
    SUFaceRef face = SU_INVALID;
    SUPoint3D vertices[4] = { {0, 0, 0},
                             {100, 0, 0},
                             {100, 0, 100},
                             {0, 0, 100} };
    SUFaceCreate(&face, vertices, &outer_loop);
    // Add the face to the entities
    SUEntitiesAddFaces(entities, 1, &face);

    // Transform Face. 90 degrees around ORIGIN and Z_AXIS.
    // Use result from Ruby API Geom::Transformation.roation(ORIGIN, Z_AXIS, 90.degrees).to_a
    SUTransformation tr{ 0.0, 1.0, 0.0, 0.0, -1.0, 0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 };
    std::vector<SUEntityRef> edges{ get_edges(entities) };
    res = SUEntitiesTransform(entities, edges.size(), &edges[0], &tr);
    std::cout << sketchup_error_string(res, __FILE__, __LINE__) << "\n";
    //_RPT1(_CRT_WARN, "%s", res);

    // Save the in-memory model to a file
    res = SUModelSaveToFile(model, "new_model.skp");
    assert(res == SU_ERROR_NONE);
    std::cout << sketchup_error_string(res, __FILE__, __LINE__) << "\n";
    // Must release the model or there will be memory leaks
    SUModelRelease(&model);
    // Always terminate the API when done using it
    SUTerminate();
    return 0;
    //std::cout << __LINE__ << "\n";
}
