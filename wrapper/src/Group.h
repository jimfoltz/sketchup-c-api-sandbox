#pragma once

#include "DrawingElement.h"

class Group : public DrawingElement
{
public:
    Group();
    Group(SUGroupRef);
    std::string type_name() {
        return "Group";
    }
private:
    SUGroupRef _ref;
};
