#include <SDL.h>

#include <iostream>

#include "Asteroid.hpp"

using namespace std;

Asteroid::Asteroid(Vector position, const Vector& velocity, SpriteID sprite_id)
    : Entity(position, velocity, 0, sprite_id) {}

float random_thang() {
    return rand() / float(RAND_MAX) - 0.5;
}

list<unique_ptr<Entity>> Asteroid::bullet_hit() {
    this->alive = false;

    list<unique_ptr<Entity>> new_asteroids = {};
    
    if (this->sprite_id != ASTEROID_8) {
        new_asteroids.push_back(make_unique<Asteroid>(
            position,
            Vector(velocity.x + random_thang(), velocity.y + random_thang()),
             static_cast<SpriteID>(sprite_id + 1)));

        new_asteroids.push_back(make_unique<Asteroid>(
            position,
            Vector(velocity.x + random_thang(), velocity.y + random_thang()),
             static_cast<SpriteID>(sprite_id + 1)));

        new_asteroids.push_back(make_unique<Asteroid>(
            position,
            Vector(velocity.x + random_thang(), velocity.y + random_thang()),
             static_cast<SpriteID>(sprite_id + 1)));
    }

    return new_asteroids;
}
