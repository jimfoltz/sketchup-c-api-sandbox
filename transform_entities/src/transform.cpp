#include <SketchUpAPI/slapi.h>
#include <SketchUpAPI/geometry.h>
#include <SketchUpAPI/initialize.h>
#include <SketchUpAPI/model/model.h>
#include <SketchUpAPI/model/entities.h>
#include <SketchUpAPI/model/face.h>
#include <SketchUpAPI/model/edge.h>
#include <SketchUpAPI/model/vertex.h>
#include <vector>

std::vector<SUEntityRef> get_edges(SUEntitiesRef entities)
{
    size_t amount{ 0 };
    SUEntitiesGetNumEdges(entities, false, &amount);
    if (amount > 0) {
        size_t count{ 0 };
        std::vector<SUEdgeRef> edges(amount);
        SUEntitiesGetEdges(entities, false, amount, &edges[0], &count);
        if (count > 0) {
            std::vector<SUEntityRef> ents{};
            for (auto& edge : edges) {
                ents.push_back(SUEdgeToEntity(edge));
            }
            return ents;
        }
    }
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

    // Transform Face
    SUTransformation tr{ 0.0, 1.0, 0.0, 0.0, -1.0, 0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 };
    std::vector<SUEntityRef> edges{ get_edges(entities) };
    size_t s{ 4 };
    res = SUEntitiesTransform(entities, s, &edges[0], &tr);
    //_RPT1(_CRT_WARN, "%s", res);

    // Save the in-memory model to a file
    SUModelSaveToFile(model, "new_model.skp");
    // Must release the model or there will be memory leaks
    SUModelRelease(&model);
    // Always terminate the API when done using it
    SUTerminate();
    return 0;
}
