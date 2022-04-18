#ifndef SDL_CONTEXT_HPP
#define SDL_CONTEXT_HPP

#include <vector>

#include <SDL2/SDL.h>

#include "Sprite.hpp"

using namespace std;

enum SpriteID {
    DUDE,
    ASTEROID_128,
    ASTEROID_64,
    ASTEROID_32,
    ASTEROID_16,
    ASTEROID_8,
    BULLET,
    NUM_SPRITES
};

class SDLContext {
public:
    SDLContext();
    ~SDLContext();
    
    SDL_Renderer *renderer = NULL;

    Sprite sprites[NUM_SPRITES];

private:
    SDL_Joystick* joystick = NULL;
    SDL_Window *window = NULL;
};

#endif // SDL_CONTEXT_HPP
