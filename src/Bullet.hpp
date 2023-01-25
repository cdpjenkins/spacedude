#ifndef BULLET_HPP
#define BULLET_HPP

#include <list>
using namespace std;

#include "Entity.hpp"

class Bullet : public Entity {
public:
    int lifetime = 100;

    Bullet(Vector& position, Vector& velocity)
        : Entity(position, velocity, 0, SpriteID::BULLET) {}

    SDL_Texture *get_texture(SDLContext *sdl);
    list<unique_ptr<Entity>> update(list<unique_ptr<Entity>> &all_entities);
};

#endif // BULLET_HPP