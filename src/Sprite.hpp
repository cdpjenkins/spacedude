#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "SDL.h"

enum SpriteID {
    DUDE,
    ASTEROID_128,
    ASTEROID_64,
    ASTEROID_32,
    ASTEROID_16,
    ASTEROID_8,
    BULLET,
    NUM_SPRITES
};

class Sprite {
public:
    float collision_radius;

    Sprite(float collision_radius);
private:

};

extern Sprite sprites[NUM_SPRITES];

#endif // SPRITE_HPP
