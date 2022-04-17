#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"

class Bullet : public Entity {
public:
    int lifetime = 100;

    Bullet(Vector& position, Vector& velocity)
        : Entity(position, velocity) {
            // meh
        }

    SDL_Texture *get_texture(SDLContext *sdl);
    void move();
};

#endif // BULLET_HPP