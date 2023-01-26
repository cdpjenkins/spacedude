#include <iostream>
#include <cmath>
#include <list>

using namespace std;

#include "Dude.hpp"
#include "Bullet.hpp"

using namespace std;

const float g = 0.005;

Dude::Dude(Vector position, float theta)
    : Entity(position, Vector::ZERO(), theta, SpriteID::DUDE) {
    this->acceleration = 0.01;
}

list<unique_ptr<Entity>> Dude::update(list<unique_ptr<Entity>> &all_entities) {
    Entity::update(all_entities);

    if (gun_energy < 0) {
        gun_energy++;
    }

    return {};
}

void Dude::draw(SDL_Renderer *renderer, SDLContext *sdl) {
    // // TODO this is largely duplicated with the implementation in Asteroid right now
    Vector screen_position = position.to_screen_coords(HEIGHT);
    Vector thang = position + direction() * 100;

    SDL_FRect dest = {.x = screen_position.x, .y = screen_position.y};

    int w, h;

    SDL_QueryTexture(get_texture(sdl), nullptr, nullptr, &w, &h);
    dest.w = w;
    dest.h = h;
    dest.x -= (dest.w / 2);
	dest.y -= (dest.h / 2);
	SDL_RenderCopyExF(renderer, get_texture(sdl), nullptr, &dest, theta, nullptr, SDL_FLIP_NONE);
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

unique_ptr<Bullet> Dude::fire_new_bullet() {
    if (gun_energy >= 0) {
        Vector bullet_position = position;
        Vector bullet_velocity = velocity + direction() * 5;

        gun_energy -= 0;

        return make_unique<Bullet>(bullet_position, bullet_velocity);
    } else {
        return nullptr;
    }
}
