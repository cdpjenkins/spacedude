#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Dude.hpp"

using namespace std;

const int JOYSTICK_DEAD_ZONE = 1000;
int joystick_x = 0;
int joystick_y = 0;

SDL_Texture *dude_texture;
SDL_Joystick* gGameController = NULL;

void render(SDL_Renderer *renderer, Dude *dude) {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    int w, h;
    SDL_Rect dest = {.x = static_cast<int>(dude->x), .y = static_cast<int>(dude->y)};
    
    dest.x -= (dest.w / 2);
	dest.y -= (dest.h / 2);

    SDL_QueryTexture(dude_texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopyEx(renderer, dude_texture, NULL, &dest, dude->theta, NULL, SDL_FLIP_NONE);

    SDL_RenderPresent(renderer);
}

int main(int argc, char** argv) {
    Dude dude(500.0f, 500.0f, 0.0f);

    bool keys[SDL_NUM_SCANCODES];
    memset(keys, 0, sizeof(keys));

    int rc = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    if (rc != 0) {
        throw exception();
    }

    cout << "Number of joysticks: " << SDL_NumJoysticks() << endl;

    if( SDL_NumJoysticks() < 1 )
    {
        printf( "Warning: No joysticks connected!\n" );
    } else {
        gGameController = SDL_JoystickOpen(0);
        if( gGameController == NULL )
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

    // this doesn't work and I don't understand why
    SDL_RaiseWindow(window);
    SDL_SetWindowInputFocus(window);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    dude_texture = IMG_LoadTexture(renderer, "assets/dude.png");

    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            switch (e.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYUP:
                    keys[e.key.keysym.scancode] = false;
                    break;
                case SDL_KEYDOWN:
                    keys[e.key.keysym.scancode] = true;
                    break;
                case SDL_JOYAXISMOTION:
                    if(e.jaxis.axis == 0 ) {
                        cout << "Joystick x: " << e.jaxis.value << endl;
                        if (abs(e.jaxis.value) > JOYSTICK_DEAD_ZONE) {
                            joystick_x = e.jaxis.value;
                        } else {
                            joystick_x = 0;
                        }
                    } else if (e.jaxis.axis == 1) {
                        cout << "Joystick y: " << e.jaxis.value << endl;
                        if (abs(e.jaxis.value) > JOYSTICK_DEAD_ZONE) {
                            joystick_y = e.jaxis.value;
                        } else {
                            joystick_y = 0;
                        }
                    } else {
                        cout << "Something else: " << e.jaxis.axis << endl;
                    }

            }
        }

        if (joystick_x != 0 && joystick_y != 0) {
            dude.theta = atan2(joystick_x, -joystick_y) * 180 / M_PI;
        }

        if (keys[SDL_SCANCODE_UP]) {
            dude.accelerate_forwards();
        }
        if (keys[SDL_SCANCODE_DOWN]) {
            // dude.y += 1;
        }
        if (keys[SDL_SCANCODE_RIGHT]) {
            dude.theta += 1;

            cout << dude.theta << endl;
        }
        if (keys[SDL_SCANCODE_LEFT]) {
            dude.theta -= 1;

            cout << dude.theta << endl;
        }
        if (keys[SDL_SCANCODE_Q]) {
            quit = true;
        }

        dude.move();

        // Uint32 time_before_step = SDL_GetTicks();
        // grid.step();
        Uint32 time_after_step_before_draw = SDL_GetTicks();
        // cout << "Time to step: " << (time_after_step_before_draw - time_before_step) << endl;
        render(renderer, &dude);
        SDL_UpdateWindowSurface(window);
        Uint32 time_after_draw = SDL_GetTicks();
        // cout << "Time to draw: " << (time_after_draw - time_after_step_before_draw) << endl;
    }

    SDL_JoystickClose( gGameController );
    gGameController = NULL;

    //Destroy window    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}
