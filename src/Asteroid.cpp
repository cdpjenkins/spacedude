#include <SDL2/SDL.h>

#include <iostream>

#include "Asteroid.hpp"

using namespace std;

Asteroid::Asteroid(Vector position, Vector velocity, SpriteID sprite_id)
    : Entity(position, velocity, 0, sprite_id) {}

vector<Entity *> Asteroid::bullet_hit() {
    this->alive = false;

    return vector<Entity *>();
}
