#include <iostream>
#include <cmath>

#include "Dude.hpp"

using namespace std;

const float g = 0.005;

Dude::Dude(float x, float y, float theta, SDL_Texture *texture) {
    this->x = x;
    this->y = y;
    this->theta = theta;

    this->texture = texture;

    this->vx = 0;
    this->vy = 0;
    this->acceleration = 0.01;
}

void Dude::move() {
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

void Dude::draw(SDL_Renderer *renderer) {
    // TODO this is largely duplicated with the implementation in Asteroid right now

    int w, h;
    SDL_Rect dest = {.x = static_cast<int>(x), .y = static_cast<int>(y)};
    
    dest.x -= (dest.w / 2);
	dest.y -= (dest.h / 2);

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopyEx(renderer, texture, NULL, &dest, theta, NULL, SDL_FLIP_NONE);
}

void Dude::accelerate_forwards() {
    Vector dir = direction();

    vx += dir.x * acceleration;
    vy -= dir.y * acceleration;
}

Vector Dude::direction() {
    float radians = theta * M_PI / 180;

    float dir_x = sin(radians);
    float dir_y = cos(radians);

    return Vector {.x = dir_x, .y = dir_y};
}
