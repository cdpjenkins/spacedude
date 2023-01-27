#include <SDL.h>

#include <iostream>

#include "Asteroid.hpp"
#include "Bullet.hpp"

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

list<unique_ptr<Entity>> Asteroid::try_bullet_hit(Bullet &bullet, list<unique_ptr<Entity>> &entities) {
    float distance = this->position.distance_to(bullet.position);
    if (distance < sprites[this->sprite_id].collision_radius + sprites[bullet.sprite_id].collision_radius) {
        list<unique_ptr<Entity>> new_asteroids = this->bullet_hit();
        this->alive = false;
        bullet.alive = false;

        for (unique_ptr<Entity> &item: new_asteroids) {
            entities.push_back(std::move(item));
        }
        return {};
    } else {
        return {};
    }
}
