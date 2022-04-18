#include <iostream>

#include "Bullet.hpp"
#include "Asteroid.hpp"

using namespace std;

SDL_Texture *Bullet::get_texture(SDLContext *sdl) {
    return sdl->textures[BULLET];
}

vector<Entity *> Bullet::update(vector<Entity *> all_entities) {
    Entity::update(all_entities);

    lifetime -= 1;
    if (lifetime <= 0) {
        alive = false;
    } else {
        for (auto& entity : all_entities) {
            if (entity != this) {
                Asteroid * asteroid = dynamic_cast<Asteroid *>(entity);
                if (asteroid != NULL) {

                    float distance = this->position.distance_to(asteroid->position);

                    if (distance < sprites[this->sprite_id].collision_radius + sprites[asteroid->sprite_id].collision_radius) {
                        vector<Entity *> new_asteroids = asteroid->bullet_hit();
                        this->alive = false;
                        return new_asteroids;
                    }
                }
            }
        }
    }

    return vector<Entity *>();
}
