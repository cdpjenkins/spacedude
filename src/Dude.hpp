
#ifndef DUDE_HPP
#define DUDE_HPP

#include <SDL2/SDL.h>

#include "Entity.hpp"

class Dude : public Entity {
public:
    float x;
    float y;
    float theta;
    float dx;
    float dy;
    float acceleration = 0.01;
    SDL_Texture *texture = NULL;

    Dude(float x, float y, float theta, SDL_Texture *texture);

    void move();
    void draw(SDL_Renderer *renderer);
    void accelerate_forwards();
};

#endif // DUDE_HPP
