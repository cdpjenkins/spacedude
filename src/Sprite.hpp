#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "SDL2/SDL.h"

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
    SpriteID id;
    float collision_radius;

    Sprite() {}
    Sprite(SpriteID id, float collision_radius);

    static Sprite make_from_texture(SDL_Renderer *renderer, const char *texture_filename, float collision_radius);
private:

};

extern Sprite sprites[NUM_SPRITES];

#endif // SPRITE_HPP
