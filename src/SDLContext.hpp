#ifndef SDL_CONTEXT_HPP
#define SDL_CONTEXT_HPP

#include <vector>

#include <SDL.h>

#include "Sprite.hpp"

using namespace std;

class SDLContext {
public:
    SDLContext();
    ~SDLContext();
    
    SDL_Renderer *renderer = NULL;

    SDL_Texture *textures[NUM_SPRITES];

private:
    SDL_Joystick* joystick = NULL;
    SDL_Window *window = NULL;
};

#endif // SDL_CONTEXT_HPP
