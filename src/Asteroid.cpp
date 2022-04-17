#include <SDL2/SDL.h>

#include <iostream>

#include "Asteroid.hpp"

using namespace std;

Asteroid::Asteroid(float x, float y, float vx, float vy, SDL_Texture *texture) {
    this->position = Vector(x, y);
    this->velocity = Vector(vx, vy);

    this->theta = 0;

    this->texture = texture;
}

