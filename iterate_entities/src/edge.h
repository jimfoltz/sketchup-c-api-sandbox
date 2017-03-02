#pragma once


#include "DrawingElement.h"

class Edge : public DrawingElement {
public:
    Edge();
    Edge(SUEdgeRef e);
    std::string type_name() const;
    ~Edge();
private:
    SUEdgeRef m_ref;
};
