#include "Entity.hpp"

void Entity::move() {
    // this is the wrong place for this!
    const int WIDTH = 1280;
    const int HEIGHT = 800;

    x += vx;
    y += vy;

    if (x > WIDTH) x -= WIDTH;
    if (x < 0) x += WIDTH;
    if (y > HEIGHT) y -= HEIGHT;
    if (y < 0) y += HEIGHT;
}
