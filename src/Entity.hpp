#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <list>
using namespace std;

#include <SDL.h>

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
    SpriteID sprite_id;

    SDL_Texture *texture = NULL;

    Entity(Vector& position, Vector velocity, float theta, SpriteID sprite_id) {
        this->position = position;
        this->velocity = velocity;
        this->theta = theta;
        this->sprite_id = sprite_id;

        this->alive = true;
    }

    virtual ~Entity() {}
    virtual list<unique_ptr<Entity>> update(list<unique_ptr<Entity>> &all_entities);
    void draw(SDL_Renderer *renderer, SDLContext *sdl);
    SDL_Texture *get_texture(SDLContext *sdl) const;
    virtual list<unique_ptr<Entity>> bullet_hit() { return {}; };
};

#endif // ENTITY_HPP
