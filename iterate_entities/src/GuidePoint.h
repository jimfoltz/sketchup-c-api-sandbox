#pragma once

#include "DrawingElement.h"

class GuidePoint : public DrawingElement
{
public:
    GuidePoint();
    GuidePoint(SUGuidePointRef);
    std::string type_name() { return "GuidePoint"; }
    ~GuidePoint();
private:
    SUGuidePointRef _ref;
};