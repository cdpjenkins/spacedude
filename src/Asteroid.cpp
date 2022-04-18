#include <SDL2/SDL.h>

#include <iostream>

#include "Asteroid.hpp"

using namespace std;

Asteroid::Asteroid(Vector position, Vector velocity, TextureID texture_id)
    : Entity(position, velocity, 0, texture_id) {}

vector<Entity *> Asteroid::bullet_hit() {
    this->alive = false;

    return vector<Entity *>();
}
