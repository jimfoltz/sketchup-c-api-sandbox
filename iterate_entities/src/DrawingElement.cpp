#include "DrawingElement.h"


DrawingElement::DrawingElement()
{
}

DrawingElement::DrawingElement(SUDrawingElementRef r) :
    Entity(SUDrawingElementToEntity(r)), m_ref(r)
{
}


DrawingElement::~DrawingElement()
{
}
