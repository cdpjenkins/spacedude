#ifndef SDL_CONTEXT_HPP
#define SDL_CONTEXT_HPP

#include <SDL2/SDL.h>

#include "Dude.hpp"

class SDLContext {
public:
    SDLContext();
    ~SDLContext();

    // this is the wrong place for this
    SDL_Texture *dude_texture = NULL;

    SDL_Texture *asteroid128_texture = NULL;
    SDL_Texture *asteroid64_texture = NULL;
    SDL_Texture *asteroid32_texture = NULL;
    SDL_Texture *asteroid16_texture = NULL;
    SDL_Texture *asteroid8_texture = NULL;

    SDL_Texture *bullet_texture = NULL;
    
    SDL_Renderer *renderer = NULL;

    SDL_GLContext gContext;
    SDL_Window *window = NULL;

private:
    SDL_Joystick* joystick = NULL;
};

#endif // SDL_CONTEXT_HPP
