#include <iostream>

#include "Bullet.hpp"

using namespace std;

SDL_Texture *Bullet::get_texture(SDLContext *sdl) {
    return sdl->bullet_texture;
}

void Bullet::move() {
    Entity::move();

    lifetime -= 1;
    if (lifetime <= 0) {
        alive = false;
    }
}
