#include <cmath>
#include <list>
#include "Dude.hpp"
#include "Bullet.hpp"
using namespace std;

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
    // TODO this is largely duplicated with the implementation in Asteroid right now
    // also surely it should be a virtual function
    Vector screen_position = position.to_screen_coords(HEIGHT);

    SDL_FRect dest = {.x = screen_position.x, .y = screen_position.y};

    int w, h;

    SDL_QueryTexture(get_texture(sdl), nullptr, nullptr, &w, &h);
    dest.w = static_cast<float>(w);
    dest.h = static_cast<float>(h);
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
    auto radians = (float)(theta * M_PI / 180);

    auto dir_x = sin(radians);
    auto dir_y = cos(radians);

    return {dir_x, dir_y};
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
