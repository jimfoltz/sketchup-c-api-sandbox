#pragma once

#include "DrawingElement.h"

class Face : public DrawingElement {

public:
    Face() {}
    Face(SUFaceRef f) : m_ref(f),
        DrawingElement(SUFaceToDrawingElement(f))
        {}

    std::string type_name() const {
        return "Face";
    }

private:
    SUFaceRef m_ref;
};

