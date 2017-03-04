#pragma once

#include "DrawingElement.h"

class Edge : public DrawingElement {
public:
    Edge();
    Edge(SUEdgeRef);
    std::string type_name() const;
    ~Edge();
private:
    SUEdgeRef _ref;
};
