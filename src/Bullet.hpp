#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"

class Bullet : public Entity {
public:
    Bullet(Vector& position, Vector& velocity)
        : Entity(position, velocity) {
            // meh
        }

    SDL_Texture *get_texture(SDLContext *sdl);
};

#endif // BULLET_HPP