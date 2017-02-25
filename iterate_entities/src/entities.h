#ifndef _ENTITIES_H
#define _ENTITIES_H

#include <SketchUpAPI\sketchup.h>
#include <vector>
#include <assert.h>
#include "model.h"


class Entities {
public:
  Entities(SUModelRef m) {
    assert(SUIsValid(m) == true);
    model_ref = m;
    SUModelGetEntities(model_ref, &_entities);
  }
  std::vector<Face> faces()
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
private:
  SUEntitiesRef _entities;
  SUModelRef model_ref;
};

#endif
