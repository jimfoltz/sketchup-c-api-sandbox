#pragma once

#include "DrawingElement.h"

class ComponentInstance : public DrawingElement
{
public:
    ComponentInstance();
    ComponentInstance(SUComponentInstanceRef);
    std::string type_name() const;
private:
    SUComponentInstanceRef _ref;
};
