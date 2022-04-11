#include <iostream>

#include <SDL2/SDL.h>

#include "Game.hpp"
#include "SDLContext.hpp"

using namespace std;

Game::Game(SDLContext *sdl) {
    this->sdl = sdl;

    dude = new Dude(600, 400, 0, sdl->dude_texture);

    entities.push_back(new Asteroid(200, 200, 1.3, 0.46, sdl->asteroid8_texture));
    entities.push_back(new Asteroid(300, 300, -0.42, -0.2, sdl->asteroid16_texture));
    entities.push_back(new Asteroid(400, 400, -1.1, -1.2, sdl->asteroid32_texture));
    entities.push_back(new Asteroid(500, 500, -0.9, 2.7, sdl->asteroid64_texture));
    entities.push_back(new Asteroid(600, 600, 0.7001, 2.2, sdl->asteroid128_texture));
}

Game::~Game() {
    for (auto& asteroid : entities) {
        delete asteroid;
    }

    delete dude;
}

void Game::main_loop() {
    bool keys[SDL_NUM_SCANCODES];
    memset(keys, 0, sizeof(keys));

    SDL_Event e;
    bool quit = false;
    Uint32 last_ticks = 0;
    while (!quit){
        // Uint32 new_ticks = SDL_GetTicks();
        // cout << new_ticks - last_ticks << endl;
        // last_ticks = new_ticks;
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
            dude->theta = atan2(joystick_x, -joystick_y) * 180 / M_PI;
        }

        if (keys[SDL_SCANCODE_UP]) {
            dude->accelerate_forwards();
        }
        if (keys[SDL_SCANCODE_DOWN]) {
            // dude.y += 1;
        }
        if (keys[SDL_SCANCODE_RIGHT]) {
            dude->theta += 1;
        }
        if (keys[SDL_SCANCODE_LEFT]) {
            dude->theta -= 1;
        }
        if (keys[SDL_SCANCODE_Q]) {
            quit = true;
        }

        dude->move();
        for (auto const& asteroid : entities) {
            asteroid->move();
        }

        render(sdl->renderer);
    }
}

void Game::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    dude->draw(renderer);

    for (auto& entity : entities) {
        entity->draw(renderer);
    }

    SDL_RenderPresent(renderer);
}
