#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SDL2/SDL.h>

#include "Entity.hpp"

class Asteroid : public Entity {
public:
    Asteroid(Vector position, Vector velocity, SDL_Texture *texture);

    SDL_Texture *get_texture(SDLContext *sdl);
};

#endif //  ASTEROID_HPP
