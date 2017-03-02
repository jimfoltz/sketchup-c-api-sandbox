#include "edge.h"

Edge::Edge() {}

Edge::Edge(SUEdgeRef e) :
    DrawingElement(SUEdgeToDrawingElement(e)),
    m_ref(e) {}

std::string Edge::type_name() const
{
    return "Edge";
}

Edge::~Edge()
{
}
