#include "GuideLine.h"

GuideLine::GuideLine() {}

GuideLine::GuideLine(SUGuideLineRef r):
    _ref(r), DrawingElement(SUGuideLineToDrawingElement(r))
{}

std::string type_name()
{
    return "GuideLine";
}