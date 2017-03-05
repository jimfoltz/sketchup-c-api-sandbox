#include "entity.h"
#include "type_name.h"

Entity::Entity() {}

Entity::Entity(SUEntityRef entity) :m_ref(entity) {}

std::string Entity::type_name() const
{
    return ::gtype_name(m_ref);
}

int64_t Entity::persistent_id() const
{
    int64_t pid = 0;
    SUEntityGetPersistentID(m_ref, &pid);
    return pid;
}

int32_t Entity::entity_id() const
{
    int32_t id = 0;
    SUEntityGetID(m_ref, &id);
    return id;
}

std::ostream& operator<<(std::ostream& os, const Entity& entity) {
    //if () {}
    os << "<" << entity.type_name() << ":" << entity.entity_id() << ">";
    return os;
}
