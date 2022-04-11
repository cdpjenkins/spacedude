#include <SDL2/SDL.h>

#include <iostream>

#include "Asteroid.hpp"

using namespace std;

Asteroid::Asteroid(float x, float y, float vx, float vy, SDL_Texture *texture) {
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->texture = texture;
}

void Asteroid::draw(SDL_Renderer *renderer) {
    int w, h;
    SDL_Rect dest = {.x = static_cast<int>(x), .y = static_cast<int>(y)};

    dest.x -= (dest.w / 2);
	dest.y -= (dest.h / 2);

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopyEx(renderer, texture, NULL, &dest, 0, NULL, SDL_FLIP_NONE);
}

void Asteroid::move() {
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
