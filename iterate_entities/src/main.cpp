#include <SketchUpAPI/sketchup.h>
#include <iostream>
#include <string>
#include <io.h>
#include "utilities/sketchup_error_string.h"
#include "wrapper/src/Model.h"

//#include "funcs.h"



int main(int argc, char *argv[])
{
    using std::cout;
    using std::endl;

    if (argc != 2)
    {
        cout << "Usage: main.exe filename.skp\n";
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
    cout << model.version_string() << "\n";

    // get the Entities object
    auto entities{ model.entities() };

    // get a list of all Entity objects
    auto all_ents{ entities.all() };

    // List all entities
    cout << "All Entities:\n";
    for (auto &e : all_ents) {
        cout << e << endl;
    }
    cout << "--\n";

    // Edges
    cout << "Edges:\n";
    for (auto& edge : entities.edges()) {
        cout << edge << "\n";
    }

    // List only Faces
    cout << "Faces:\n";
    for (auto& face : entities.faces()) {
        cout << face << endl;
    }

    auto groups{ entities.groups() };
    for (auto& group : groups) {
        cout << group << endl;
    }

    cout << "Guide Points:\n";
    for (auto& gp : entities.guide_points()) {
        cout << gp << "\n";
    }

    cout << "Guide Lines:\n";
    for (auto& gl : entities.guide_lines()) {
        cout << gl << "\n";
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
