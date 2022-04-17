#include <iostream>
#include <cmath>

#include "Dude.hpp"
#include "Bullet.hpp"

using namespace std;

const float g = 0.005;

Dude::Dude(Vector position, float theta, SDL_Texture *texture)
    : Entity(position, Vector::ZERO()) {

    this->theta = theta;

    this->texture = texture;

    this->acceleration = 0.01;
}

void Dude::draw(SDL_Renderer *renderer, SDLContext *sdl) {
    // // TODO this is largely duplicated with the implementation in Asteroid right now
    Vector screen_position = position.to_screen_coords(HEIGHT);
    Vector thang = position + direction() * 100;
    Vector screen_thang = thang.to_screen_coords(HEIGHT);

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLineF(renderer, screen_position.x, screen_position.y, screen_thang.x, screen_thang.y);

    SDL_FRect dest = {.x = screen_position.x, .y = screen_position.y};

    int w, h;

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    dest.w = w;
    dest.h = h;
    dest.x -= (dest.w / 2);
	dest.y -= (dest.h / 2);
	SDL_RenderCopyExF(renderer, texture, NULL, &dest, theta, NULL, SDL_FLIP_NONE);
}

SDL_Texture *Dude::get_texture(SDLContext *sdl) {
    return sdl->dude_texture;
}

void Dude::accelerate_forwards() {
    Vector dir = direction();
    dir *= acceleration;

    velocity += dir;
}

Vector Dude::direction() {
    float radians = theta * M_PI / 180;

    float dir_x = sin(radians);
    float dir_y = cos(radians);

    return Vector(dir_x, dir_y);
}

Bullet *Dude::fire_new_bullet() {
    Vector bullet_position = position;
    Vector bullet_velocity = velocity + direction() * 5;

    return new Bullet(bullet_position, bullet_velocity);
}
