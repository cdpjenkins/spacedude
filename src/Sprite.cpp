#include <exception>

#include <SDL2/SDL_image.h>

#include "Sprite.hpp"

using namespace std;

Sprite sprites[] = {
    Sprite(DUDE, 16),
    Sprite(ASTEROID_128, 40),
    Sprite(ASTEROID_64, 20),
    Sprite(ASTEROID_32, 10),
    Sprite(ASTEROID_16, 5),
    Sprite(ASTEROID_8, 3),
    Sprite(BULLET, 2)
};

Sprite::Sprite(SpriteID id, float collision_radius) {
    this->id = id;
    this->collision_radius = collision_radius;
}
