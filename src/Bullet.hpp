#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"

class Bullet : Entity {
public:
    void move();
    void draw(SDL_Renderer *renderer);
};

#endif // BULLET_HPP