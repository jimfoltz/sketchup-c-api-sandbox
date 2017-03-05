#include "Face.h"

Face::Face() {}

Face::Face(SUFaceRef f) :
    _ref(f),
    DrawingElement(SUFaceToDrawingElement(f))
{}

std::string Face::type_name() const {
    return "Face";
}

Face::~Face()
{
}
