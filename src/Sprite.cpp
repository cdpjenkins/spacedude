#include <exception>

#include <SDL2/SDL_image.h>

#include "Sprite.hpp"

using namespace std;

Sprite::Sprite(float collision_radius, SDL_Texture *texture) {
    this->collision_radius = collision_radius;
    this->texture = texture;
}

Sprite Sprite::make_from_texture(SDL_Renderer *renderer, const char *texture_filename, float collision_radius) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, texture_filename);
    if (texture == NULL) {
        throw exception();
    }

    return Sprite(collision_radius, texture);
}
