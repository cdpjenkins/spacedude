#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SDL.h>

#include "Entity.hpp"

class Asteroid : public Entity {
public:
    Asteroid(Vector position, const Vector& velocity, SpriteID sprite_id);

    list<unique_ptr<Entity>> bullet_hit() override;
};

#endif //  ASTEROID_HPP
