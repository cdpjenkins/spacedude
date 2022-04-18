#include <SDL2/SDL.h>

#include <iostream>

#include "Asteroid.hpp"

using namespace std;

Asteroid::Asteroid(Vector position, Vector velocity, TextureID texture_id)
    : Entity(position, velocity, texture_id) {

    this->theta = 0;
}

