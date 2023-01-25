#ifndef GAME_HPP
#define GAME_HPP

#include <list>

#include "Dude.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "SDLContext.hpp"

using namespace std;

class Game {
public:
    Game(SDLContext *sdl);
    ~Game();

    Dude *dude = NULL;
    list<unique_ptr<Entity>> entities = {};

    void main_loop();
    void render(SDL_Renderer *renderer);

private:
    const int JOYSTICK_DEAD_ZONE = 1000;

    SDLContext *sdl;

    int joystick_x = 0;
    int joystick_y = 0;
};

#endif // GAME_HPP
