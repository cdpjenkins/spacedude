#include "Sprite.hpp"

using namespace std;

Sprite sprites[] = {
        Sprite(16),
    Sprite(40),
    Sprite(20),
    Sprite(10),
    Sprite(5),
    Sprite(3),
    Sprite(2)
};

Sprite::Sprite(float collision_radius) :
        collision_radius(collision_radius)
{}
