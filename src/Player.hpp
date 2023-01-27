
#ifndef DUDE_HPP
#define DUDE_HPP

#include <memory>
using namespace std;

#include <SDL.h>

#include "Bullet.hpp"
#include "Entity.hpp"
#include "SDLContext.hpp"
#include "Shield.hpp"
#include "Vector.hpp"

class Player : public Entity {
public:
    float acceleration = 0.01;

    Player(Vector positionf, float theta);

    void update(list<unique_ptr<Entity>> &all_entities) override;
    void draw(SDL_Renderer *renderer, SDLContext *sdl) override;
    void accelerate_forwards();
    Vector direction();
    unique_ptr<Bullet> fire_new_bullet();

private:
    int gun_energy = 0;
    Shield shield;
};

#endif // DUDE_HPP
