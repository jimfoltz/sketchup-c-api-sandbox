#pragma once

#include "entity.h"

class DrawingElement :
    public Entity
{
public:
    DrawingElement();
    DrawingElement(SUDrawingElementRef);
    ~DrawingElement();
private:
    SUDrawingElementRef m_ref;
};

