#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

class Entity {
private:
    int entity_ = 0; // Default value initialized
public:
    Entity();
    Entity(const int& x);
    Entity(const Entity& entity); // Copy constructor
    ~Entity();

    // Marked as const => can not assign data members here
    void getEntity() const;

    // const reference => no parameter modified here
    void setEntity(const int& ent);
};

#endif // ENTITY_H
