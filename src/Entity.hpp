#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>

#include "Vector.hpp"

class Entity {
public:
    // this is the wrong place for this!
    static const int WIDTH = 1280;
    static const int HEIGHT = 800;

    Vector position;
    float theta;
    Vector velocity;

    SDL_Texture *texture = NULL;

    virtual ~Entity() {}
    void move();
    void draw(SDL_Renderer *renderer);
};

#endif // ENTITY_HPP
