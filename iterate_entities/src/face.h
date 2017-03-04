#pragma once

#include "DrawingElement.h"

class Face : public DrawingElement {
public:
    Face();
    Face(SUFaceRef);
    std::string type_name() const;
    ~Face();
private:
    SUFaceRef m_ref;
};

