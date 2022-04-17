#include <iostream>
#include <cmath>

#include "Dude.hpp"

using namespace std;

const float g = 0.005;

Dude::Dude(float x, float y, float theta, SDL_Texture *texture) {
    this->position = Vector {.x = x, .y = y};
    this->velocity = Vector {.x = 0, .y = 0};

    this->theta = theta;

    this->texture = texture;

    this->acceleration = 0.01;
}

void Dude::draw(SDL_Renderer *renderer) {
    // // TODO this is largely duplicated with the implementation in Asteroid right now
    Vector screen_position = position.to_screen_coords(HEIGHT);

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLineF(renderer, screen_position.x, screen_position.y, screen_position.x + 100, screen_position.y + 100);


    SDL_FRect dest = {.x = screen_position.x, .y = screen_position.y};
    
    dest.x -= (dest.w / 2);
	dest.y -= (dest.h / 2);

    int w, h;

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    dest.w = w;
    dest.h = h;
	SDL_RenderCopyExF(renderer, texture, NULL, &dest, theta, NULL, SDL_FLIP_NONE);
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

    return Vector {.x = dir_x, .y = dir_y};
}
