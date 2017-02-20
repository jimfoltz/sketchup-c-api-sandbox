#include <cassert>
#include <string>
#include <SketchUpAPI/model/defs.h>
#include <SketchUpAPI/model/entity.h>

std::string type_name(SUEntityRef const &entity) {
	SURefType t = SUEntityGetType(entity);
	assert(t != SURefType_Unknown);
	std::string str = "";
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
	case SURefType_Unknown:
		str = "Unknown";
		break;
	default:
		str = "Unknown";
	}
	return str;
}