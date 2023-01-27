#include <iostream>

#include "Bullet.hpp"

using namespace std;

void Bullet::update(list<unique_ptr<Entity>> &all_entities) {
    Entity::update(all_entities);

    lifetime -= 1;
    if (lifetime <= 0) {
        alive = false;
    } else {
        // It would still be useful to use some kind of data sctructure that causes us to only call try_bullet_hit() on
        // objects that are nearby
        // Some options listed in this post:
        // https://www.toptal.com/game/video-game-physics-part-ii-collision-detection-for-solid-objects
        // e.g. sort-and-sweep
        for (auto &entity: all_entities) {
            bool did_the_bullet_hit_us = entity->try_bullet_hit(*this, all_entities);
            if (did_the_bullet_hit_us) {
                return;
            }
        }
    }
}
