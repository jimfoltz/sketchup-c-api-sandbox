
#include "ComponentDefinition.h"

ComponentDefinition::ComponentDefinition()
{
}

ComponentDefinition::ComponentDefinition(SUComponentDefinitionRef ref)
    : DrawingElement(SUComponentDefinitionToDrawingElement(ref)), _ref(ref)
{
}

std::string ComponentDefinition::name() const {
    SUStringRef name = SU_INVALID;
    SUStringCreate(&name);
    SUComponentDefinitionGetName(_ref, &name);
    size_t name_length = 0;
    SUStringGetUTF8Length(name, &name_length);
    char* name_utf8 = new char[name_length + 1];
    SUStringGetUTF8(name, name_length + 1, name_utf8, &name_length);
    // Now we have the name in a form we can use
    SUStringRelease(&name);
    std::string n{ name_utf8 };
    delete[]name_utf8;
    return n;
}