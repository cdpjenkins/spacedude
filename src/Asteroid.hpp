#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SDL2/SDL.h>

class Asteroid {
public:
    float x;
    float y;
    float vx;
    float vy;
    SDL_Texture *texture;

    Asteroid(float x, float y, float vx, float vy, SDL_Texture *texture);

    void draw(SDL_Renderer *renderer);
    void move();
};

#endif //  ASTEROID_HPP
