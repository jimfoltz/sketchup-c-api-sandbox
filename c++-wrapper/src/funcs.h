#ifndef _FUNCS_H
#define _FUNCS_H

int32_t entity_get_id(SUEntityRef& entity)
{
  int32_t id = 0;
  SUEntityGetID(entity, &id);
  return id;
}

int64_t entity_get_persistent_id(const SUEntityRef& entity)
{
  int64_t id = 0;
  SUEntityGetPersistentID(entity, &id);
  return id;
}

std::ostream& operator<< (std::ostream& os, const SUEntityRef& obj) {
  os << "#<" << type_name(obj) << ":" << entity_get_persistent_id(obj) << ">";
  return os;
}

std::ostream& operator<< (std::ostream& out, std::vector<SUEntityRef>& v) {
  out << "[";
  std::ostream_iterator<SUEntityRef> out_it(out, ", ");
  std::copy(v.begin(), v.end(), out_it);
  out << "]";// << std::endl;
  return out;
}

void entities_get_faces(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumFaces(entities, &len);
  if (len > 0) {
    size_t num = 0;
    std::vector<SUFaceRef> faces(len);
    SUEntitiesGetFaces(entities, len, &faces[0], &num);
    if (num > 0) {
      for (auto face : faces) {
        SUEntityRef ent = SU_INVALID;
        ent = SUFaceToEntity(face);
        v.push_back(ent);
      }
    }
  }
}

void entities_get_edges(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUResult result = SUEntitiesGetNumEdges(entities, false, &len);
  if (len > 0) {
    size_t num = 0;
    std::vector<SUEdgeRef> edges(len);
    SUEntitiesGetEdges(entities, false, len, &edges[0], &num);
    if (num > 0) {
      for (auto edge : edges) {
        SUEntityRef ent = SU_INVALID;
        ent = SUEdgeToEntity(edge);
        v.push_back(ent);
      }
    }
  }
}

void entities_get_groups(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumGroups(entities, &len);
  if (len > 0) {
    std::vector<SUGroupRef> groups(len);
    size_t num = 0;
    SUEntitiesGetGroups(entities, len, &groups[0], &num);
    if (num > 0) {
      for (auto group : groups) {
        v.push_back(SUGroupToEntity(group));
      }
    }
  }
}

void entities_get_instances(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumInstances(entities, &len);
  if (len > 0) {
    std::vector<SUComponentInstanceRef> instances(len);
    size_t num = 0;
    SUEntitiesGetInstances(entities, len, &instances[0], &num);
    if (num > 0) {
      for (auto instance : instances) {
        v.push_back(SUComponentInstanceToEntity(instance));
      }
    }
  }
}

void entities_get_guide_points(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumGuidePoints(entities, &len);
  if (len > 0) {
    std::vector<SUGuidePointRef> cpoints(len);
    size_t num = 0;
    SUEntitiesGetGuidePoints(entities, len, &cpoints[0], &num);
    if (num > 0) {
      for (auto cpoint : cpoints) {
        v.push_back(SUGuidePointToEntity(cpoint));
      }
    }
  }
}

void entities_get_guide_lines(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumGuideLines(entities, &len);
  if (len > 0) {
    std::vector<SUGuideLineRef> clines(len);
    size_t num = 0;
    SUEntitiesGetGuideLines(entities, len, &clines[0], &num);
    if (num > 0) {
      for (auto cline : clines) {
        v.push_back(SUGuideLineToEntity(cline));
      }
    }
  }
}

void entities_get_dimensions(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumDimensions(entities, &len);
  if (len > 0) {
    std::vector<SUDimensionRef> dims(len);
    size_t num = 0;
    SUEntitiesGetDimensions(entities, len, &dims[0], &num);
    if (num > 0) {
      for (auto dim : dims) {
        v.push_back(SUDimensionToEntity(dim));
      }
    }
  }
}

void entities_get_images(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumImages(entities, &len);
  if (len > 0) {
    std::vector<SUImageRef> images(len);
    size_t num = 0;
    SUEntitiesGetImages(entities, len, &images[0], &num);
    if (num > 0) {
      for (auto image : images) {
        v.push_back(SUImageToEntity(image));
      }
    }
  }
}

void entities_get_section_planes(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumSectionPlanes(entities, &len);
  if (len > 0) {
    std::vector<SUSectionPlaneRef> planes(len);
    size_t num = 0;
    SUEntitiesGetSectionPlanes(entities, len, &planes[0], &num);
    if (num > 0) {
      for (auto plane : planes) {
        v.push_back(SUSectionPlaneToEntity(plane));
      }
    }
  }
}

void entities_get_polyline3ds(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  size_t len = 0;
  SUEntitiesGetNumPolyline3ds(entities, &len);
  if (len > 0) {
    std::vector<SUPolyline3dRef> plines(len);
    size_t num = 0;
    SUEntitiesGetPolyline3ds(entities, len, &plines[0], &num);
    if (num > 0) {
      for (auto pline : plines) {
        v.push_back(SUPolyline3dToEntity(pline));
      }
    }
  }
}

void entities_get_entities(SUEntitiesRef& entities, std::vector<SUEntityRef>& v)
{
  entities_get_edges(entities, v);
  entities_get_faces(entities, v);
  entities_get_groups(entities, v);
  entities_get_instances(entities, v);
  entities_get_guide_points(entities, v);
  entities_get_guide_lines(entities, v);
  entities_get_dimensions(entities, v);
  entities_get_section_planes(entities, v);
  entities_get_images(entities, v);
  entities_get_polyline3ds(entities, v);
}

void get_entities(SUModelRef model, std::vector<SUEntityRef>& v) {
  SUEntitiesRef entities = SU_INVALID;
  SUModelGetEntities(model, &entities);
  entities_get_entities(entities, v);
}

void get_entities(SUGroupRef group, std::vector<SUEntityRef>& v)
{
  SUEntitiesRef entities = SU_INVALID;
  SUGroupGetEntities(group, &entities);
  entities_get_entities(entities, v);
}

void get_entities(SUComponentDefinitionRef definition, std::vector<SUEntityRef>& v)
{
  SUEntitiesRef entities = SU_INVALID;
  SUComponentDefinitionGetEntities(definition, &entities);
  entities_get_entities(entities, v);
}

#endif
