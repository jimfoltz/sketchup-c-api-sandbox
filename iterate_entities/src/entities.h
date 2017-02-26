#pragma once

#include <SketchUpAPI\sketchup.h>
#include <vector>
#include <assert.h>
#include "model.h"
#include "face.h"
#include "edge.h"


class Entities {

public:

    Entities(SUModelRef m) {
        assert(SUIsValid(m) == true);
        model_ref = m;
        SUModelGetEntities(model_ref, &_entities);
    }

    std::vector<Face> faces() const
    {
        std::vector<Face> face_list(0);
        size_t count = 0;
        SUEntitiesGetNumFaces(_entities, &count);
        if (count > 0) {
            std::vector<SUFaceRef> face_refs(count);
            size_t n = 0;
            SUEntitiesGetFaces(_entities, count, &face_refs[0], &n);
            if (n > 0) {
                for (auto face_ref : face_refs) {
                    face_list.push_back(Face(face_ref));
                }
            }
        }
        return face_list;
    }

    std::vector<Edge> edges() const
    {
        std::vector<Edge> list(0);
        size_t count = 0;
        SUEntitiesGetNumEdges(_entities, false, &count);
        if (count > 0) {
            std::vector<SUEdgeRef> refs(count);
            size_t n = 0;
            SUEntitiesGetEdges(_entities, false, count, &refs[0], &n);
            if (n > 0) {
                for (auto ref : refs) {
                    list.push_back(Edge(ref));
                }
            }
        }
        return list;
    }

private:

    SUEntitiesRef _entities;
    SUModelRef model_ref;

};

