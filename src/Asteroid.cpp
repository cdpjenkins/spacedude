#include <SDL2/SDL.h>

#include <iostream>

#include "Asteroid.hpp"

using namespace std;

Asteroid::Asteroid(Vector position, Vector velocity, SDL_Texture *texture)
    : Entity(position, velocity) {

    this->theta = 0;

    this->texture = texture;
}


SDL_Texture *Asteroid::get_texture(SDLContext *sdl) {
    return sdl->asteroid64_texture;
}
