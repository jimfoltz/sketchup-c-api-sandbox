#pragma once

#include "DrawingElement.h"

class ComponentDefinition : public DrawingElement
{
public:
    ComponentDefinition();
    ComponentDefinition(SUComponentDefinitionRef);
    std::string name() const;

private:
    SUComponentDefinitionRef _ref;
};
