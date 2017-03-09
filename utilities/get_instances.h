

std::vector<SUComponentInstanceRef> get_instances(SUEntitiesRef entities)
{
    size_t num{ 0 };
    SUEntitiesGetNumInstances(entities, &num);
    std::vector<SUComponentInstanceRef> refs(num);
    size_t count{ 0 };
    SUEntitiesGetInstances(entities, num, &refs[0], &count);
    return refs;
}

