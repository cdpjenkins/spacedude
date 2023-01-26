#ifndef BULLET_HPP
#define BULLET_HPP

#include <list>
using namespace std;

#include "Entity.hpp"

class Bullet : public Entity {
public:
    int lifetime = 100;

    Bullet(Vector& position, Vector& velocity)
        : Entity(position, velocity, 0, SpriteID::BULLET) {}

    list<unique_ptr<Entity>> update(list<unique_ptr<Entity>> &all_entities) override;
};

#endif // BULLET_HPP