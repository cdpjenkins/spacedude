#include <iostream>

#include "Bullet.hpp"
#include "Asteroid.hpp"

using namespace std;

SDL_Texture *Bullet::get_texture(SDLContext *sdl) {
    return sdl->textures[BULLET];
}

list<unique_ptr<Entity>> Bullet::update(list<unique_ptr<Entity>> &all_entities) {
    Entity::update(all_entities);

    lifetime -= 1;
    if (lifetime <= 0) {
        alive = false;
    } else {
        for (auto& entity : all_entities) {
            if (entity.get() != this) {
                float distance = this->position.distance_to(entity->position);

                if (distance < sprites[this->sprite_id].collision_radius + sprites[entity->sprite_id].collision_radius) {
                    Asteroid * asteroid;

                    // still a bit of a freaking hack... if anything other than an asteroid gets hit by a bullet then
                    // we don't want to do anything... but we haven't pulled the logic into the right place to be able
                    // to easily handle that
                    //
                    // Need a method in the Entity class that does multiple things:
                    // - tells you whether the entity got hit
                    // - returns list of newly spawned entities
                    // That method can then do nothing for objects that don't get hit
                    //
                    // Also need to be smarter about collision detection so we don't have to compare every bullet with
                    // every single asteroid each time. Must... research... clever... algorithms...

                    // oh god this is even worse now!!!1
                    if ((asteroid = dynamic_cast<Asteroid *>(entity.get())) != nullptr) {
                        list<unique_ptr<Entity>> new_asteroids = asteroid->bullet_hit();
                        this->alive = false;
                        return new_asteroids;
                    }
                }
            }
        }
    }

    return {};
}
