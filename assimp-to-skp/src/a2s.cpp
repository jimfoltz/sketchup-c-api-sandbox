#include <SketchUpAPI/SketchUp.h>

#include <iostream>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/DefaultLogger.hpp>

#include "output_sketchup_error.h"

// #define SU_CALL(func) if ((func) != SU_ERROR_NONE) throw std::exception()

// Quick debugging
#define CHECK(r) if (r != SU_ERROR_NONE) { \
	std::cout << "SU Error line: " << __LINE__ << "\n"; \
	output_sketchup_error(r); return 1; }

int main(int argc, char *argv[]) {

   if (argc < 2)
   {
      std::cout << "Usage: " << argv[0] << " file\n";
      return 1;
   }

   //const double Scale{ 39.3701 };
   const double Scale{ 1000.0 };
   // Log to STDERR in this case
   //Assimp::DefaultLogger::create("", Assimp::Logger::VERBOSE, aiDefaultLogStream_STDERR);

   Assimp::Importer importer;

   // std::string exts = "";
   // importer.GetExtensionList(exts);
   // std::cout << exts << std::endl;

   std::string filename = argv[1];
   std::string logname = filename + ".log";
   Assimp::DefaultLogger::create(logname.c_str());

   const aiScene *scene = importer.ReadFile(
         filename,
         aiProcess_JoinIdenticalVertices |
         aiProcess_Triangulate |
         aiProcess_ValidateDataStructure |
         aiProcess_PreTransformVertices |
         0
         );

   if (!scene)
   {
      std::cout << "An error occured: " << importer.GetErrorString() << "\n";
      return 1;
   }

   // Setup the SketchUp API data structures.

   // Always initialize the API before using it
   SUInitialize();

   // Create the model
   SUModelRef model = SU_INVALID;
   SUResult res = SUModelCreate(&model);
   CHECK(res);

   // Get the entity container of the model
   SUEntitiesRef entities = SU_INVALID;
   res = SUModelGetEntities(model, &entities);
   CHECK(res);

   //unsigned int mesh_index;
   aiMesh *mesh;
   unsigned int face_count = 0;
   aiVector3D vertex;

   // Iterate each scene mesh
   //for (unsigned int i = 0; i < root_node->mNumMeshes; i++) {
   for (unsigned int i = 0; i < scene->mNumMeshes; i++) {

      mesh = scene->mMeshes[i];
      face_count = mesh->mNumFaces;

      // Create a new Group for each Mesh
      SUGroupRef grp = SU_INVALID;
      res = SUGroupCreate(&grp);
      CHECK(res);

      res = SUEntitiesAddGroup(entities, grp);
      CHECK(res);

      SUEntitiesRef gents = SU_INVALID;
      res = SUGroupGetEntities(grp, &gents);
      CHECK(res);

      SUGeometryInputRef geom_input = SU_INVALID;
      res = SUGeometryInputCreate(&geom_input);
      CHECK(res);

      SULoopInputRef outer_loop = SU_INVALID;

      aiFace *faces = mesh->mFaces;
      unsigned int v_i;
      int c = 0;
      for (size_t i = 0; i < face_count; i++) 
      {
         // std::cout << "Face " << i << " has " << faces[i].mNumIndices << " vertices.\n";

         // Create a Loop for each face
         res = SULoopInputCreate(&outer_loop);

         for (size_t j = 0; j < faces[i].mNumIndices; j++) 
         {
            v_i = faces[i].mIndices[j];
            // std::cout << v_i << " ";
            vertex = mesh->mVertices[v_i];
            SUPoint3D pt;
            pt.x = vertex.x * Scale;
            pt.y = vertex.y * Scale;
            pt.z = vertex.z * Scale;

            res = SUGeometryInputAddVertex(geom_input, &pt);
            CHECK(res);

            res = SULoopInputAddVertexIndex(outer_loop, c);
            CHECK(res);
            c++;
         }
         res = SUGeometryInputAddFace(geom_input, &outer_loop, NULL);
         CHECK(res);
         SULoopInputRelease(&outer_loop);
      }
      res = SUEntitiesFill(entities, geom_input, true);
      CHECK(res);
      SUGeometryInputRelease(&geom_input);
   }

   std::string outname = (std::string)filename + ".skp";
   std::cout << "Writing model...\n";
   res = SUModelSaveToFileWithVersion(model, outname.c_str(), SUModelVersion::SUModelVersion_SU2014);
   CHECK(res);
   if (res == SU_ERROR_NONE)
   {
	   std::cout << "Success." << "\n";
   }

   res = SUModelRelease(&model);
   CHECK(res);

   SUTerminate();

   // ShellExecute(GetDesktopWindow(), "open", outname.c_str(), NULL, NULL, SW_SHOW);
   // system("pause");
   return 0;
}
