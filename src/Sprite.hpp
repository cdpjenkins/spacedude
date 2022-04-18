#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "SDL2/SDL.h"

class Sprite {
public:
    float collision_radius;
    SDL_Texture *texture;

    Sprite() {}
    Sprite(float collision_radius, SDL_Texture *texture);

    static Sprite make_from_texture(SDL_Renderer *renderer, const char *texture_filename, float collision_radius);
private:

};

#endif // SPRITE_HPP
