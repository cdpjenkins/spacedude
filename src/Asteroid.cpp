#include <SDL.h>

#include <iostream>

#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Dude.hpp"
#include "Entity.hpp"

using namespace std;

Asteroid::Asteroid(Vector position, const Vector& velocity, SpriteID sprite_id)
    : Entity(position, velocity, 0, sprite_id) {}

float random_thang() {
    return rand() / float(RAND_MAX) - 0.5;
}

list<unique_ptr<Entity>> Asteroid::shatter(list<unique_ptr<Entity>> &all_entities) {
    this->alive = false;

    if (this->sprite_id != ASTEROID_8) {
        all_entities.push_back(make_unique<Asteroid>(
            position,
            Vector(velocity.x + random_thang(), velocity.y + random_thang()),
             static_cast<SpriteID>(sprite_id + 1)));

        all_entities.push_back(make_unique<Asteroid>(
            position,
            Vector(velocity.x + random_thang(), velocity.y + random_thang()),
             static_cast<SpriteID>(sprite_id + 1)));

        all_entities.push_back(make_unique<Asteroid>(
            position,
            Vector(velocity.x + random_thang(), velocity.y + random_thang()),
             static_cast<SpriteID>(sprite_id + 1)));
    }

    return {};
}

bool Asteroid::try_bullet_hit(Bullet &bullet, list<unique_ptr<Entity>> &entities) {
    if (collides_with(bullet)) {
        bullet.alive = false;
        this->shatter(entities);
        return true;
    } else {
        return false;
    }
}

// TODO - remove duplication a-plenty in this method
// probably by just pulling everything into shatter() and renaming that
bool Asteroid::try_player_hit(Dude &bullet, list<unique_ptr<Entity>> &entities) {
    if (collides_with(bullet)) {
        // TODO some negative consequences for the player, perchance...
        this->shatter(entities);

        return true;
    } else {
        return false;
    }
}
