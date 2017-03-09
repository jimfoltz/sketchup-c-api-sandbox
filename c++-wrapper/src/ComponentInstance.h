#pragma once

#include "DrawingElement.h"

class ComponentInstance : public DrawingElement
{
public:
    ComponentInstance();
    ComponentInstance(SUComponentInstanceRef);
    std::string type_name() const;
    SUResult save_as(std::string) const;
private:
    SUComponentInstanceRef _ref;
};
