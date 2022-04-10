#include <SDL2/SDL.h>

#include <iostream>

#include "Asteroid.hpp"

using namespace std;

Asteroid::Asteroid(float x, float y, SDL_Texture *texture) {
    this->x = x;
    this->y = y;
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
