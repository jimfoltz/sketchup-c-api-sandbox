#include <SketchUpAPI/sketchup.h>
#include <vector>
#include <iostream>
#include <Model.h>


int main(int argc, char *argv[]) {
    // Always initialize the API before using it
    SUInitialize();

    auto model = Model::create("C:/Users/Jim/SketchUp/_source/jf-sketchup-c-api-sandbox/test-model.skp");

    auto& instances{ model.entities().instances() };

    std::cout << instances[0] << "\n";

    instances[0].save_as("output.skp");

    SUTerminate();
    return 0;
}

