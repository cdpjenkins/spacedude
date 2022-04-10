#include <iostream>

#include <SDL2/SDL.h>

#include "App.hpp"
#include "SDLContext.hpp"

using namespace std;

App::App(SDLContext *sdl) {
    this->sdl = sdl;
}

void App::main_loop() {
    bool keys[SDL_NUM_SCANCODES];
    memset(keys, 0, sizeof(keys));

    SDL_Event e;
    bool quit = false;
    Uint32 last_ticks = 0;
    while (!quit){
        Uint32 new_ticks = SDL_GetTicks();
        cout << new_ticks - last_ticks << endl;
        last_ticks = new_ticks;

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
        }
        if (keys[SDL_SCANCODE_LEFT]) {
            dude.theta -= 1;
        }
        if (keys[SDL_SCANCODE_Q]) {
            quit = true;
        }

        dude.move();

        // Uint32 time_before_step = SDL_GetTicks();
        // grid.step();
        Uint32 time_after_step_before_draw = SDL_GetTicks();
        // cout << "Time to step: " << (time_after_step_before_draw - time_before_step) << endl;
        sdl->render(&dude);
        Uint32 time_after_draw = SDL_GetTicks();
        // cout << "Time to draw: " << (time_after_draw - time_after_step_before_draw) << endl;
    }

}