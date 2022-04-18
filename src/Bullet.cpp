#include <iostream>

#include "Bullet.hpp"
#include "Asteroid.hpp"

using namespace std;

SDL_Texture *Bullet::get_texture(SDLContext *sdl) {
    return sdl->sprites[BULLET].texture;
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

                    if (distance < 50) {
                        asteroid->bullet_hit();
                        this->alive = false;
                    }
                }
            }
        }
    }

    return vector<Entity *>();
}
