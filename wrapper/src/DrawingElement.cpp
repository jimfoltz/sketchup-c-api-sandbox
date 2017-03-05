#include "DrawingElement.h"


DrawingElement::DrawingElement()
{
}

DrawingElement::DrawingElement(SUDrawingElementRef ref) :
    Entity(SUDrawingElementToEntity(ref)), m_ref(ref)
{
}


DrawingElement::~DrawingElement()
{
}
