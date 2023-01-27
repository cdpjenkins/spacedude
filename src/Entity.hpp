#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <list>
using namespace std;

#include <SDL.h>

#include "SDLContext.hpp"
#include "Vector.hpp"

class Bullet;

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

    Entity(Vector& position, const Vector& velocity, float theta, SpriteID sprite_id) {
        this->position = position;
        this->velocity = velocity;
        this->theta = theta;
        this->sprite_id = sprite_id;

        this->alive = true;
    }

    virtual ~Entity() = default;
    virtual list<unique_ptr<Entity>> update(list<unique_ptr<Entity>> &all_entities);
    virtual void draw(SDL_Renderer *renderer, SDLContext *sdl);
    SDL_Texture *get_texture(SDLContext *sdl) const;
    virtual list<unique_ptr<Entity>> bullet_hit() { return {}; };

    virtual list<unique_ptr<Entity>> try_bullet_hit(Bullet &bullet, list<unique_ptr<Entity>> &entities) { return {}; };
};

#endif // ENTITY_HPP
