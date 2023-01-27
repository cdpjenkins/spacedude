#include <iostream>

#include <SDL.h>

#include "Game.hpp"
#include "SDLContext.hpp"

using namespace std;

Game::Game(SDLContext *sdl) :
    sdl(sdl),
    dude(make_unique<Dude>(Vector(600, 400), 0))

{
    entities.push_back(make_unique<Asteroid>(Vector(200, 200), Vector(1.3, 0.46), SpriteID::ASTEROID_128));
    entities.push_back(make_unique<Asteroid>(Vector(300, 300), Vector(-0.42, -0.2), SpriteID::ASTEROID_128));
    entities.push_back(make_unique<Asteroid>(Vector(400, 400), Vector(-1.1, -1.2), SpriteID::ASTEROID_128));
    entities.push_back(make_unique<Asteroid>(Vector(500, 500), Vector(-0.9, 2.7), SpriteID::ASTEROID_128));
    entities.push_back(make_unique<Asteroid>(Vector(600, 600), Vector(0.7001, 2.2), SpriteID::ASTEROID_128));
}

Game::~Game() = default;

void Game::main_loop() {
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
            dude->theta = static_cast<float>(atan2(joystick_x, -joystick_y) * 180 / M_PI);
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
        if (keys[SDL_SCANCODE_F]) {
            unique_ptr<Entity> new_bullet = dude->fire_new_bullet();
            if (new_bullet) {
                entities.push_back(std::move(new_bullet));
            }
        }

        dude->update(entities);
        for (auto const& entity : entities) {
            entity->update(entities);
        }

        // oh man this is so much more horrible than it needs to be
        // all we want to do is remove !alive elements from the list
        // TODO pull into a remove_dead_entities() function so at least
        // we don't have to look at it...
        entities.erase(
            remove_if(entities.begin(), entities.end(),
                [](unique_ptr<Entity>& entity) { return !(entity->alive); }),
            entities.end()
        );

        render(sdl->renderer);
    }
}

void Game::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    dude->draw(renderer, sdl);

    for (auto& entity : entities) {
        entity->draw(renderer, sdl);
    }

    SDL_RenderPresent(renderer);
}
