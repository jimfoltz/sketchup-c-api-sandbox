#include "edge.h"

Edge::Edge() {}

Edge::Edge(SUEdgeRef e) :
    DrawingElement(SUEdgeToDrawingElement(e)),
    _ref(e) {}

std::string Edge::type_name() const
{
    return "Edge";
}

Edge::~Edge()
{
}
