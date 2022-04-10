#include <iostream>
#include <cmath>

#include "Dude.hpp"

using namespace std;

const float g = 0.005;

Dude::Dude(float x, float y, float theta) {
    this->x = x;
    this->y = y;
    this->theta = theta;
    this->dx = 0;
    this->dy = 0;
    this->acceleration = 0.01;
}

void Dude::move() {
    // dy += g;

    x += dx;
    y += dy;
}

void Dude::accelerate_forwards() {
    float radians = theta * M_PI / 180 ;

    float dir_x = sin(radians);
    float dir_y = cos(radians);

    // cout << dir_x << "," << dir_y << endl;

    dx += dir_x * acceleration;
    dy -= dir_y * acceleration;
}
