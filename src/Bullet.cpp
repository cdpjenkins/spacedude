#include <iostream>

#include "Bullet.hpp"

using namespace std;

SDL_Texture *Bullet::get_texture(SDLContext *sdl) {
    return sdl->bullet_texture;
}

vector<Entity *> Bullet::update() {
    Entity::update();

    lifetime -= 1;
    if (lifetime <= 0) {
        alive = false;
    }

    return vector<Entity *>();
}
