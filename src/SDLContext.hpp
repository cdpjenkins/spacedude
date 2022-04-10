#ifndef SDL_CONTEXT_HPP
#define SDL_CONTEXT_HPP

#include <SDL2/SDL.h>

#include "Dude.hpp"

class SDLContext {
public:
    SDLContext();
    ~SDLContext();

    void render(Dude *dude);

private:
    SDL_Joystick* joystick = NULL;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *dude_texture = NULL;
};

#endif // SDL_CONTEXT_HPP
