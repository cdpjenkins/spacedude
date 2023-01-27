#include "Dude.hpp"
#include "Bullet.hpp"
#include "Asteroid.hpp"
#include <iostream>
#include <SDL.h>
#include <list>
using namespace std;

#include "Entity.hpp"

using namespace std;

void Entity::update(list<unique_ptr<Entity>> &all_entities) {
    position += velocity;

    if (position.x > WIDTH) position.x -= WIDTH;
    if (position.x < 0) position.x += WIDTH;
    if (position.y > HEIGHT) position.y -= HEIGHT;
    if (position.y < 0) position.y += HEIGHT;
}

void Entity::draw(SDL_Renderer *renderer, SDLContext *sdl) {
    float x = position.x;
    float y = HEIGHT - position.y;

    SDL_Texture *texture = get_texture(sdl);

    SDL_Rect dest = {.x = static_cast<int>(x), .y = static_cast<int>(y)};
    SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);

    dest.x -= (dest.w / 2);
	dest.y -= (dest.h / 2);

	SDL_RenderCopyEx(renderer, texture, nullptr, &dest, theta, nullptr, SDL_FLIP_NONE);
}

SDL_Texture *Entity::get_texture(SDLContext *sdl) const {
    return sdl->textures[sprite_id];
}

bool Entity::collides_with(Entity &that) const {
    float distance = position.distance_to(that.position);
    bool collides = distance < sprites[sprite_id].collision_radius + sprites[that.sprite_id].collision_radius;
    return collides;
}