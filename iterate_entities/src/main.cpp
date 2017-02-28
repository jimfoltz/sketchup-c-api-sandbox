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
//#include "type_name.h"
#include "output_sketchup_error.h"
#include "model.h"

//#include "funcs.h"


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

  for (const auto& face : faces)  {
      cout << face << endl;
  }

  for (const auto& edge : edges) {
      cout << edge << endl;
  }

  SUTerminate();
  return 0;

}
