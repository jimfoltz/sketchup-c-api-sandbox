#pragma once

#include <SketchUpAPI\sketchup.h>
#include "entity.h"

class DrawingElement : public Entity
{
public:
    DrawingElement();
    DrawingElement(SUDrawingElementRef);
    ~DrawingElement();
private:
    SUDrawingElementRef m_ref;
};

