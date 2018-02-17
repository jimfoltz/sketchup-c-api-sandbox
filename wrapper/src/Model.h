// Model.h

#pragma once

#include <SketchUpAPI/sketchup.h>
#include <string>
#include <sstream>
#include <list>
#include <utility>
#include "entities.h"

class Entities;

class Model {

public:

    //static Model create();

    static Model create(std::string path);

    Entities entities() const;

    std::string version_string() const;
    std::list < std::pair<std::string, int>> stats();

private:
    void create_from_file(std::string filename);

    SUModelRef _ref;


};
