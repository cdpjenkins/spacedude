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
    bool alive;
    TextureID texture_id;

    SDL_Texture *texture = NULL;

    Entity(Vector& position, Vector velocity, float theta, TextureID texture_id) {
        this->position = position;
        this->velocity = velocity;
        this->theta = theta;
        this->texture_id = texture_id;

        this->alive = true;
    }

    virtual ~Entity() {}
    virtual vector<Entity *> update();
    void draw(SDL_Renderer *renderer, SDLContext *sdl);
    SDL_Texture *get_texture(SDLContext *sdl);
};

#endif // ENTITY_HPP
