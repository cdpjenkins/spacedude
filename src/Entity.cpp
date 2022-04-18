#include "Entity.hpp"

vector<Entity *> Entity::update() {
    position += velocity;

    if (position.x > WIDTH) position.x -= WIDTH;
    if (position.x < 0) position.x += WIDTH;
    if (position.y > HEIGHT) position.y -= HEIGHT;
    if (position.y < 0) position.y += HEIGHT;

    return vector<Entity *>();
}

void Entity::draw(SDL_Renderer *renderer, SDLContext *sdl) {
    int w, h;
    float x = position.x;
    float y = HEIGHT - position.y;

    SDL_Texture *texture = get_texture(sdl);

    SDL_Rect dest = {.x = static_cast<int>(x), .y = static_cast<int>(y)};
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    dest.x -= (dest.w / 2);
	dest.y -= (dest.h / 2);

	SDL_RenderCopyEx(renderer, texture, NULL, &dest, theta, NULL, SDL_FLIP_NONE);
}

SDL_Texture *Entity::get_texture(SDLContext *sdl) {
    return sdl->textures[texture_id];
}
