#include <SketchUpAPI/sketchup.h>
#include <iostream>
#include <ostream>
#include <string>
//#include <unordered_map>
#include <vector>
//#include <cassert>
//#include <algorithm>
#include <iterator> // ostream_inserter
#include <sstream>
#include "type_name.h"
#include "output_sketchup_error.h"
#include "model.h"

#include "funcs.h"


int main(int argc, char* argv[])
{
  using std::cout;
  using std::endl;

  if (argc != 2) {
    std::cout << "Usage: main.exe filename.skp" << std::endl;
    return EXIT_FAILURE;
  }
  std::string filename = argv[1];

  SUInitialize();

  auto model = Model::create(filename);
  cout << model.version() << std::endl;

  auto ents = model.entities();

  auto faces = ents.faces();
  cout << "Faces: " << faces.size() << endl;

  auto edges = ents.edges();
  cout << "Edges: " << edges.size() << endl;


  //// List Model entities
  //std::vector<SUEntityRef> ents(0);
  //model.get_entities(model, ents);
  //std::cout << "Entities for Model:" << std::endl;
  //std::cout << ents;
  //std::cout << "\nModel contains: " << ents.size() << " entities." << std::endl;

  //// Groups
  //std::vector<SUEntityRef> groups(0);
  //for (auto& ent : ents) {
  //  if (SUEntityGetType(ent) == SURefType_Group) {
  //    groups.push_back(ent);
  //  }
  //}
  //std::cout << "Model contains " << groups.size() << " Groups." << std::endl;
  //for (auto& ent : groups) {
  //  std::cout << "Entities for " << ent << ":\n";
  //  ents.clear();
  //  get_entities(SUGroupFromEntity(ent), ents);
  //  std::cout << ents << " ";
  //  std::cout << "\nGroup " << ent << " contains " << ents.size() << " entities." << std::endl;
  //}

  SUTerminate();
  return 0;

}
