
#ifndef DUDE_HPP
#define DUDE_HPP

#include <SDL2/SDL.h>

#include "Entity.hpp"
#include "Vector.hpp"

class Dude : public Entity {
public:
    float acceleration = 0.01;

    Dude(float x, float y, float theta, SDL_Texture *texture);

    void draw(SDL_Renderer *renderer);
    void accelerate_forwards();
    Vector direction();
};

#endif // DUDE_HPP
