#include "Entity.hpp"

void Entity::move() {
    position += velocity;

    if (position.x > WIDTH) position.x -= WIDTH;
    if (position.x < 0) position.x += WIDTH;
    if (position.y > HEIGHT) position.y -= HEIGHT;
    if (position.y < 0) position.y += HEIGHT;
}

void Entity::draw(SDL_Renderer *renderer) {
    int w, h;
    float x = position.x;
    float y = HEIGHT - position.y;
    SDL_Rect dest = {.x = static_cast<int>(x), .y = static_cast<int>(y)};
    
    dest.x -= (dest.w / 2);
	dest.y -= (dest.h / 2);

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopyEx(renderer, texture, NULL, &dest, theta, NULL, SDL_FLIP_NONE);
}
