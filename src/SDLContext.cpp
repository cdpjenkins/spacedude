#include <exception>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "SDLContext.hpp"

using namespace std;

SDLContext::SDLContext() {
    int rc = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    if (rc != 0) {
        throw exception();
    }

    cout << "Number of joysticks: " << SDL_NumJoysticks() << endl;
    if( SDL_NumJoysticks() < 1 )
    {
        printf( "Warning: No joysticks connected!\n" );
    } else {
        joystick = SDL_JoystickOpen(0);
        if( joystick == NULL )
        {
            printf( "Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError() );
            throw exception();
        }

        cout << "We operned joystick 1. It'd better work!!!1" << endl;
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    SDL_Window *window = SDL_CreateWindow("Spacedude!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                        1280, 800,
                                        SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS);
    if (window == NULL) {
        throw exception();
    }
    // this doesn't work on Mac and I don't know why
    SDL_RaiseWindow(window);
    SDL_SetWindowInputFocus(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    dude_texture = IMG_LoadTexture(renderer, "assets/dude.png");

    SDL_UpdateWindowSurface(window);
}

SDLContext::~SDLContext() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_JoystickClose( joystick );
    SDL_Quit();
}
