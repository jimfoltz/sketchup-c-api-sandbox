#include "Face.h"

Face::Face() {}

Face::Face(SUFaceRef f) :
    m_ref(f),
    DrawingElement(SUFaceToDrawingElement(f))
{}

std::string Face::type_name() const {
    return "Face";
}

Face::~Face()
{
}
