#include "GuidePoint.h"

GuidePoint::GuidePoint()
{
}

GuidePoint::GuidePoint(SUGuidePointRef r)
    : _ref(r),
    DrawingElement(SUGuidePointToDrawingElement(r))
{
}

GuidePoint::~GuidePoint()
{
}
