#pragma once

#include <string>
#include "DrawingElement.h"
#include "ComponentDefinition.h"

class ComponentInstance : public DrawingElement
{
public:
    ComponentInstance();
    ComponentInstance(SUComponentInstanceRef);
    std::string type_name() const;
    std::string name() const;
    SUResult save_as(std::string) const;
    ComponentDefinition definition() const;
private:
    SUComponentInstanceRef _ref;
};
