#include <exception>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "SDLContext.hpp"

#include "Sprite.hpp"

using namespace std;

const int WIDTH = 1280;
const int HEIGHT = 800;

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
                                        WIDTH, HEIGHT,
                                        SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS);
    if (window == NULL) {
        throw exception();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    sprites[DUDE] = Sprite::make_from_texture(renderer, "assets/dude.png", 16);
    sprites[ASTEROID_128] = Sprite::make_from_texture(renderer, "assets/asteroid128.png", 64);
    sprites[ASTEROID_64] = Sprite::make_from_texture(renderer, "assets/asteroid64.png", 32);
    sprites[ASTEROID_32] = Sprite::make_from_texture(renderer, "assets/asteroid32.png", 16);
    sprites[ASTEROID_16] = Sprite::make_from_texture(renderer, "assets/asteroid16.png", 8);
    sprites[ASTEROID_8] = Sprite::make_from_texture(renderer, "assets/asteroid8.png", 4);
    sprites[BULLET] = Sprite::make_from_texture(renderer, "assets/bullet.png", 2);

    SDL_UpdateWindowSurface(window);
}

SDLContext::~SDLContext() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_JoystickClose( joystick );
    SDL_Quit();
}
