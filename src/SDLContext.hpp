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
    
    SDL_Renderer *renderer = nullptr;

    SDL_Texture *textures[NUM_SPRITES];

private:
    SDL_Joystick* joystick = nullptr;
    SDL_Window *window = nullptr;
};

#endif // SDL_CONTEXT_HPP
