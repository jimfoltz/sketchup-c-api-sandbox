#include "entities.h"
#include "Face.h"
#include "edge.h"

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
    fill_edges(ents);
    fill_faces(ents);
    return ents;
}

void Entities::fill_faces(EntityList& entity_list)
{
    size_t count = 0;
    SUEntitiesGetNumFaces(_ref, &count);
    if (count > 0) {
        std::vector<SUFaceRef> face_refs(count);
        size_t n = 0;
        SUEntitiesGetFaces(_ref, count, &face_refs[0], &n);
        if (n > 0) {
            for (auto face_ref : face_refs) {
                entity_list.push_back(Face(face_ref));
            }
        }
    }
}



void Entities::fill_edges(EntityList& entity_list)
{
    size_t count = 0;
    SUEntitiesGetNumEdges(_ref, false, &count);
    if (count > 0) {
        std::vector<SUEdgeRef> refs(count);
        size_t n = 0;
        SUEntitiesGetEdges(_ref, false, count, &refs[0], &n);
        if (n > 0) {
            for (auto ref : refs) {
                entity_list.push_back(Edge(ref));
            }
        }
    }
}
std::vector<Face> Entities::faces() const
{
    std::vector<Face> face_list(0);
    size_t count = 0;
    SUEntitiesGetNumFaces(_ref, &count);
    if (count > 0) {
        std::vector<SUFaceRef> face_refs(count);
        size_t n = 0;
        SUEntitiesGetFaces(_ref, count, &face_refs[0], &n);
        if (n > 0) {
            for (auto face_ref : face_refs) {
                face_list.push_back(Face(face_ref));
            }
        }
    }
    return face_list;
}

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

