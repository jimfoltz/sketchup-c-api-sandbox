#pragma once

#include <string>
#include <SketchUpAPI\sketchup.h>
#include <iostream>

class Entity {
public:
    Entity();
    Entity(SUEntityRef);
    virtual std::string type_name() const;
    int64_t persistent_id() const;
    int32_t entity_id() const;
    //virtual Entity to_entity() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Entity& entity);
private:
    SUEntityRef m_ref;
};
