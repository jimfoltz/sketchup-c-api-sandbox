#pragma once

#include <SketchUpAPI\sketchup.h>
#include "entity.h"

class Edge : public DrawingElement {
public:
    Edge() {}
    Edge(SUEdgeRef e) :
        DrawingElement(SUEdgeToDrawingElement(e)),
        m_ref(e) {}

    std::string type_name() const
    {
        return "Edge";
    }

private:
    SUEdgeRef m_ref;
};
