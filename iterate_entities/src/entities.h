#pragma once

#include <SketchUpAPI\sketchup.h>
#include <vector>
#include <assert.h>
#include "model.h"
#include "face.h"
#include "edge.h"


class Entities {
private:
    SUEntitiesRef _ref;
    SUModelRef model_ref;
    typedef std::vector<Entity> EntityList;
    void fill_faces(EntityList&);
    void fill_edges(EntityList&);

public:

    Entities(SUModelRef m);
    //EntityList _entities;
    std::vector<Face> faces() const;
    std::vector<Edge> edges() const;

    // 
    EntityList all();
    //typedef EntityList::iterator iterator;
    //typedef EntityList::const_iterator const_iterator;
    //iterator begin() { return _entities.begin(); }
    //iterator end() { return _entities.end(); }
    //size_t size();
};
