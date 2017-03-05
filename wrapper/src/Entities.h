#pragma once

#include <SketchUpAPI\sketchup.h>
#include <vector>
#include <assert.h>
#include "model.h"
#include "face.h"
#include "edge.h"
#include "ComponentInstance.h"
#include "Group.h"
#include "GuidePoint.h"
#include "GuideLine.h"


class Entities {
private:
    SUEntitiesRef _ref;
    SUModelRef model_ref;
    typedef std::vector<Entity> EntityList;
    

public:

    Entities(SUModelRef m);
    EntityList _entities;
    std::vector<Face> faces() const;
    std::vector<Edge> edges() const;
    std::vector<ComponentInstance> instances() const;
    std::vector<Group> groups() const;
    std::vector<GuidePoint> guide_points() const;
    std::vector<GuideLine> guide_lines() const;

    // 
    EntityList all();
    //typedef EntityList::iterator iterator;
    //typedef EntityList::const_iterator const_iterator;
    //iterator begin() { return _entities.begin(); }
    //iterator end() { return _entities.end(); }
    //size_t size();


    template<typename T, typename T2>
    std::vector<T> get1(SU_RESULT(&f)(SUEntitiesRef, size_t*), SU_RESULT(&f2)(SUEntitiesRef, size_t, T2[], size_t*)) const;

};


