#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <list>
using namespace std;

#include <SDL.h>

#include "SDLContext.hpp"
#include "Vector.hpp"

class Bullet;
class Player;

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
    virtual void update(list<unique_ptr<Entity>> &all_entities);
    virtual void draw(SDL_Renderer *renderer, SDLContext *sdl);
    SDL_Texture *get_texture(SDLContext *sdl) const;
    virtual list<unique_ptr<Entity>> shatter(list<unique_ptr<Entity>> &list1) { return {}; };

    virtual bool try_bullet_hit(Bullet &bullet, list<unique_ptr<Entity>> &entities) { return {}; };
    virtual bool try_player_hit(Player &bullet, list<unique_ptr<Entity>> &entities) { return false; };

    bool collides_with(Entity &that) const;

    float collision_radius() const;
};

#endif // ENTITY_HPP
