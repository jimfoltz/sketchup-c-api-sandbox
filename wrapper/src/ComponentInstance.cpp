
#include "ComponentInstance.h"

ComponentInstance::ComponentInstance() {}

ComponentInstance::ComponentInstance(SUComponentInstanceRef e)
    : DrawingElement(SUComponentInstanceToDrawingElement(e)), _ref(e)
{
}

std::string ComponentInstance::type_name() const
{
    return "ComponentInstance";
}

SUResult ComponentInstance::save_as(std::string filename) const
{
    return SUComponentInstanceSaveAs(_ref, filename.c_str());
}

ComponentDefinition ComponentInstance::definition() const
{
    SUComponentDefinitionRef def = SU_INVALID;
    SUComponentInstanceGetDefinition(_ref, &def);
    return ComponentDefinition{ def };
}

std::string ComponentInstance::name() const
{
    SUStringRef name = SU_INVALID;
    SUStringCreate(&name);
    SUComponentInstanceGetName(_ref, &name);
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
