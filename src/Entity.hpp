#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>

class Entity {
public:
    float x;
    float y;
    float vx;
    float vy;

    virtual ~Entity() {}
    void move();
    virtual void draw(SDL_Renderer *renderer) = 0;
};

#endif // ENTITY_HPP
