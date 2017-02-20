#include <SketchUpAPI/sketchup.h>
#include <iostream>
#include <string>
//#include <unordered_map>
#include <vector>
#include <cassert>
//#include <algorithm>
//#include <iterator> // back_inserter
#include "type_name.h"
#include "output_sketchup_error.h"

int32_t entity_get_id(SUEntityRef& const entity)
{
  int32_t id = 0;
  SUEntityGetID(entity, &id);
  return id;
}

int64_t entity_get_persistent_id(SUEntityRef& entity)
{
  int64_t id = 0;
  SUEntityGetPersistentID(entity, &id);
  return id;
}

std::ostream& operator<< (std::ostream& os, SUEntityRef& obj) {
  os << "<" << type_name(obj) << ":" << entity_get_persistent_id(obj) << ">";
  return os;
}

void entities_get_faces(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumFaces(entities, &len);
  if (len > 0) {
    size_t num = 0;
    std::vector<SUFaceRef> faces(len);
    SUEntitiesGetFaces(entities, len, &faces[0], &num);
    if (num > 0) {
      for (auto face : faces) {
        SUEntityRef ent{ SU_INVALID };
        ent = SUFaceToEntity(face);
        v.push_back(ent);
      }
    }
  }
}

void entities_get_edges(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUResult result = SUEntitiesGetNumEdges(entities, false, &len);
  if (len > 0) {
    size_t num = 0;
    std::vector<SUEdgeRef> edges(len);
    SUEntitiesGetEdges(entities, false, len, &edges[0], &num);
    if (num > 0) {
      for (auto edge : edges) {
        SUEntityRef ent{ SU_INVALID };
        ent = SUEdgeToEntity(edge);
        v.push_back(ent);
      }
    }
  }
}

void entities_get_groups(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumGroups(entities, &len);
  if (len > 0) {
    std::vector<SUGroupRef> groups(len);
    size_t num = 0;
    SUEntitiesGetGroups(entities, len, &groups[0], &num);
    if (num > 0) {
      for (auto group : groups) {
        v.push_back(SUGroupToEntity(group));
      }
    }
  }
}

void entities_get_instances(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumInstances(entities, &len);
  if (len > 0) {
    std::vector<SUComponentInstanceRef> instances(len);
    size_t num = 0;
    SUEntitiesGetInstances(entities, len, &instances[0], &num);
    if (num > 0) {
      for (auto instance : instances) {
        v.push_back(SUComponentInstanceToEntity(instance));
      }
    }
  }
}

void entities_get_entities(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  entities_get_edges(entities, v);
  entities_get_faces(entities, v);
  entities_get_groups(entities, v);
  entities_get_instances(entities, v);
}

void get_entities(SUModelRef model, std::vector<SUEntityRef>& v) {
  SUEntitiesRef entities{ SU_INVALID };
  SUModelGetEntities(model, &entities);
  entities_get_entities(entities, v);
}

void get_entities(SUGroupRef group, std::vector<SUEntityRef>& v)
{
  SUEntitiesRef entities{ SU_INVALID };
  SUGroupGetEntities(group, &entities);
  entities_get_entities(entities, v);
}

void get_entities(SUComponentDefinitionRef definition, std::vector<SUEntityRef>& v)
{
  SUEntitiesRef entities{ SU_INVALID };
  SUComponentDefinitionGetEntities(definition, &entities);
  entities_get_entities(entities, v);
}

int main(int argc, char* argv[])
{
  try {
    if (argc != 2) {
      std::cout << "Usage: main.exe filename.skp" << std::endl;
      return EXIT_FAILURE;
    }
    std::string filename = argv[1];

    SUInitialize();
    SUResult result{ SU_ERROR_NONE };
    SUModelRef model{ SU_INVALID };

    result = SUModelCreateFromFile(&model, filename.c_str());

    int major = 0, minor = 0, build = 0;
    result = SUModelGetVersion(model, &major, &minor, &build);
    std::cout << "Model Version: " << major << "." << minor << "." << build << std::endl;

    // List Model entities
    std::vector<SUEntityRef> ents(0);
    get_entities(model, ents);
    std::cout << "Entities for Model:" << std::endl;
    for (auto& ent : ents) {
      std::cout << ent << " ";
    }
    std::cout << "\nModel contains: " << ents.size() << " entities." << std::endl;

    // Groups
    std::vector<SUEntityRef> groups(0);
    for (auto& const ent : ents) {
      if (SUEntityGetType(ent) == SURefType_Group) {
        groups.push_back(ent);
      }
    }
    std::cout << "Model contains " << groups.size() << " Groups." << std::endl;
    for (auto& ent : groups) {
      std::cout << "Entities for " << ent << ":\n";
      ents.clear();
      get_entities(SUGroupFromEntity(ent), ents);
      for (auto& ent : ents) {
        std::cout << ent << " ";
      }
      std::cout << "\nGroup " << ent << " contains " << ents.size() << " entities." << std::endl;
    }

    SUTerminate();
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << "exception caught: " << e.what() << std::endl;
  }
}
