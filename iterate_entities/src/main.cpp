#include <SketchUpAPI/sketchup.h>
#include <iostream>
#include <string>
#include <io.h>
#include "output_sketchup_error.h"
#include "model.h"

//#include "funcs.h"

int main(int argc, char *argv[])
{
    using std::cout;
    using std::endl;

    if (argc != 2)
    {
        std::cout << "Usage: main.exe filename.skp" << std::endl;
        return EXIT_FAILURE;
    }
    std::string filename = argv[1];
    if (_access(filename.c_str(), 0))
    {
        cout << "Did not find file " << filename << endl;
        return EXIT_FAILURE;
    }
    SUInitialize();

    auto model = Model::create(filename);
    cout << model.version() << std::endl;

    // get the Entities object
    auto entities{ model.entities() };

    // get a list of all Entity objects
    auto all_ents{ entities.all() };

    // List all entities
    for (auto &e : all_ents) {
        cout << e << endl;
    }

    // List only Faces
    cout << "Faces:\n";
    for (auto& face : entities.faces()) {
        cout << face << endl;
    }

    cout << "Entities size: " << all_ents.size() << endl;

    cout << "\nModel Stats:" << endl;
    auto stats = model.stats();
    for (auto& elem : stats) {
        cout << elem.first << " : " << elem.second << endl;
    }

    SUTerminate();
    return EXIT_SUCCESS;
}
