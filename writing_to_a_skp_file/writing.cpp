#include <SketchUpAPI/slapi.h>
#include <SketchUpAPI/geometry.h>
#include <SketchUpAPI/initialize.h>
#include <SketchUpAPI/model/model.h>
#include <SketchUpAPI/model/entities.h>
#include <SketchUpAPI/model/face.h>
#include <SketchUpAPI/model/edge.h>
#include <SketchUpAPI/model/vertex.h>
#include <vector>
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
    SUPoint3D vertices[4] = {{0, 0, 0},
                             {100, 100, 0},
                             {100, 100, 100},
                             {0, 0, 100}};
    SUFaceCreate(&face, vertices, &outer_loop);
    // Add the face to the entities
    SUEntitiesAddFaces(entities, 1, &face);
    // Save the in-memory model to a file
    SUModelSaveToFile(model, "new_model.skp");
    // Must release the model or there will be memory leaks
    SUModelRelease(&model);
    // Always terminate the API when done using it
    SUTerminate();
    return 0;
}
