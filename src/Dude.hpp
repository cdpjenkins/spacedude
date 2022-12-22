
#ifndef DUDE_HPP
#define DUDE_HPP

#include <SDL.h>

#include "SDLContext.hpp"
#include "Entity.hpp"
#include "Vector.hpp"
#include "Bullet.hpp"

class Dude : public Entity {
public:
    float acceleration = 0.01;

    Dude(Vector position, float theta);

    list<Entity *> update(list<Entity *> all_entities);
    void draw(SDL_Renderer *renderer, SDLContext *sdl);
    void accelerate_forwards();
    Vector direction();
    Bullet *fire_new_bullet();

private:
    int gun_energy = 0;
};

#endif // DUDE_HPP
