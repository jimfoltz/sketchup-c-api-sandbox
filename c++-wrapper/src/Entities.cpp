#include "entities.h"
#include "Face.h"
#include "edge.h"
#include "ComponentInstance.h"
#include "Group.h"

Entities::Entities(SUModelRef m) {
    assert(SUIsValid(m) == true);
    //model_ref = m;
    SUModelGetEntities(m, &_ref);
    //fill_faces();
    //fill_edges();
}

Entities::EntityList Entities::all()
{
    EntityList ents(0);
    //fill_edges(ents);
    //fill_faces(ents);
    return ents;
}

template<typename T, typename T2>
 std::vector<T> Entities::get1(SU_RESULT(&f)(SUEntitiesRef, size_t *), SU_RESULT(&f2)(SUEntitiesRef, size_t, T2[], size_t *)) const {
    size_t count = 0;
    std::vector<T> list(0);
    f(_ref, &count);
    if (count > 0) {
        std::vector<T2> refs(count);
        size_t n{ 0 };
        f2(_ref, count, &refs[0], &n);
        if (n > 0) {
            for (T2& ref : refs) {
                list.push_back(T(ref));
            }
        }
    }
    return list;
}

 // edges() is special because it takes a boolean parameter
 // in the middle of the "typical" parameters.
std::vector<Edge> Entities::edges() const
{
    std::vector<Edge> list(0);
    size_t count = 0;
    SUEntitiesGetNumEdges(_ref, false, &count);
    if (count > 0) {
        std::vector<SUEdgeRef> refs(count);
        size_t n = 0;
        SUEntitiesGetEdges(_ref, false, count, &refs[0], &n);
        if (n > 0) {
            for (auto ref : refs) {
                list.push_back(Edge(ref));
            }
        }
    }
    return list;
}


std::vector<Face> Entities::faces() const
{
    return get1<Face, SUFaceRef>(SUEntitiesGetNumFaces, SUEntitiesGetFaces);
}

std::vector<ComponentInstance> Entities::instances() const {
    return this->get1<ComponentInstance, SUComponentInstanceRef>(SUEntitiesGetNumInstances, SUEntitiesGetInstances);
}

std::vector<Group> Entities::groups() const {
    return this->get1<Group, SUGroupRef>(SUEntitiesGetNumGroups, SUEntitiesGetGroups);
}

std::vector<GuidePoint> Entities::guide_points() const
{
    return this->get1<GuidePoint, SUGuidePointRef>(SUEntitiesGetNumGuidePoints, SUEntitiesGetGuidePoints);
}

std::vector<GuideLine> Entities::guide_lines() const
{
    return this->get1<GuideLine, SUGuideLineRef>(SUEntitiesGetNumGuideLines, SUEntitiesGetGuideLines);
}
