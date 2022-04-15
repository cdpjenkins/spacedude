#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SDL2/SDL.h>

#include "Entity.hpp"

class Asteroid : public Entity {
public:
    SDL_Texture *texture;

    Asteroid(float x, float y, float vx, float vy, SDL_Texture *texture);

    void draw(SDL_Renderer *renderer);
};

#endif //  ASTEROID_HPP
