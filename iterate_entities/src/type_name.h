#ifndef _TYPE_NAME_H
#define _TYPE_NAME_H

#include <cassert>
#include <string>
#include <SketchUpAPI/model/defs.h>
#include <SketchUpAPI/model/entity.h>

std::string type_name(SUEntityRef const &entity) {
  SURefType t = SUEntityGetType(entity);
  assert(t != SURefType_Unknown);
  std::string str = "";
  SUDimensionType dim_t = SUDimensionType_Invalid;
  switch (t) {
  case SURefType_Face:
    str = "Face";
    break;
  case SURefType_Edge:
    str = "Edge";
    break;
  case SURefType_Group:
    str = "Group";
    break;
  case SURefType_ComponentInstance:
    str = "ComponentInstance";
    break;
  case SURefType_GuidePoint:
    str = "GuidePoint";
    break;
  case SURefType_GuideLine:
    str = "GuideLine";
    break;
  case SURefType_Dimension:
    str = "Dimension";
    SUDimensionGetType(SUDimensionFromEntity(entity), &dim_t);
    if (dim_t == SUDimensionType_Linear)
      str = "DimensionLinear";
    if (dim_t == SUDimensionType_Radial)
      str = "DimensionRadial";
    break;
  case SURefType_SectionPlane:
    str = "SectionPlane";
    break;
  case SURefType_Image:
    str = "Image";
    break;
  case SURefType_Polyline3D:
    str = "3D Polyline";
    break;
  case SURefType_Unknown:
    str = "Unknown";
    break;
  default:
    str = "Unknown";
  }
  return str;
}

#endif
