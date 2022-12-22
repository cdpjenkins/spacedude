#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SDL.h>

#include "Entity.hpp"

class Asteroid : public Entity {
public:
    Asteroid(Vector position, Vector velocity, SpriteID sprite_id);

    list<Entity *> bullet_hit();
};

#endif //  ASTEROID_HPP
