#include <SDL2/SDL.h>

#include <iostream>

#include "Asteroid.hpp"

using namespace std;

Asteroid::Asteroid(float x, float y, float vx, float vy, SDL_Texture *texture) {
    this->position = Vector {.x = x, .y = y};
    this->velocity = Vector {.x = vx, .y = vy};

    this->theta = 0;

    this->texture = texture;
}

