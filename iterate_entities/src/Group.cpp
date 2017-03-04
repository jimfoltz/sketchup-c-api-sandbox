#include "Group.h"

Group::Group() {}

Group::Group(SUGroupRef e)
    : DrawingElement(SUGroupToDrawingElement(e)), _ref(e)
{}

