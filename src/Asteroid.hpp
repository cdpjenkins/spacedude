#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SDL.h>

#include "Entity.hpp"

class Asteroid : public Entity {
public:
    Asteroid(Vector position, const Vector& velocity, SpriteID sprite_id);

    list<unique_ptr<Entity>> shatter(list<unique_ptr<Entity>> &all_entities) override;

    bool try_bullet_hit(Bullet &bullet, list<unique_ptr<Entity>> &entities) override;
    bool try_player_hit(Dude &bullet, list<unique_ptr<Entity>> &entities);;

};

#endif //  ASTEROID_HPP
