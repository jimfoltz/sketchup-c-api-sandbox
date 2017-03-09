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
