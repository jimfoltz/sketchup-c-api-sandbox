#pragma once

#include "DrawingElement.h"

class GuideLine : public DrawingElement
{
public:
    GuideLine();
    GuideLine(SUGuideLineRef);
    std::string type_name();
private:
    SUGuideLineRef _ref;
};