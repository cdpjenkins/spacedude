#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>

#include "SDLContext.hpp"
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

    Entity(Vector& position, Vector velocity) {
        this->position = position;
        this->velocity = velocity;
    }

    virtual ~Entity() {}
    void move();
    void draw(SDL_Renderer *renderer, SDLContext *sdl);
    virtual SDL_Texture *get_texture(SDLContext *sdl) = 0;
};

#endif // ENTITY_HPP
