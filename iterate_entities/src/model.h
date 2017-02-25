#ifndef _MODEL_H
#define _MODEL_H

#include <SketchUpAPI/sketchup.h>
#include <string>

#include "face.h"
#include "entities.h"

class Model {
public:
  static Model create() {
    Model m;
    return m;
  }

  static Model create(std::string path)
  {
    Model m;
    m.create_from_file(path);
    return m;
  }

  Entities entities()
  {
    Entities e(model_ref);
    return e;
  }

  std::string version()
  {
    int major{ 0 };
    int minor{ 0 };
    int build{ 0 };
    SUModelGetVersion(model_ref, &major, &minor, &build);
    std::ostringstream os;
    os << major << "." << minor << "." << build;
    return os.str();
  }

private:
  void create_from_file(std::string filename) {
    SUModelRef model = SU_INVALID;
    SUResult res = SU_ERROR_NONE;
    SUModelCreateFromFile(&model, filename.c_str());
    assert(res == SU_ERROR_NONE);
    model_ref = model;
  }

  SUModelRef model_ref;
};

#endif
