#include <SketchUpAPI/sketchup.h>
#include <vector>
#include <iostream>
#include <wrapper\src\SUWrapper.h>


int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "usage:\n  " << argv[0] << " filename\n";
        return EXIT_FAILURE;
    }

    SUInitialize();

    auto model = Model::create(argv[1]);
    auto& instances{ model.entities().instances() };
    std::string name{};

    for (auto& instance : instances) {
        name = instance.name().empty() ? instance.definition().name() : instance.name();
        std::cout << instance << " " << name <<  "\n";
        instance.save_as(name);
        name.clear();
    }

    SUTerminate();
    return EXIT_SUCCESS;
}
