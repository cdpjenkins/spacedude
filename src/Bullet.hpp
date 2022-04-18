#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"

class Bullet : public Entity {
public:
    int lifetime = 100;

    Bullet(Vector& position, Vector& velocity)
        : Entity(position, velocity, 0, TextureID::BULLET_TEXTURE) {}

    SDL_Texture *get_texture(SDLContext *sdl);
    vector<Entity *> update();
};

#endif // BULLET_HPP