#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

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
    vector<Entity*> entities = vector<Entity*>();

    void main_loop();
    void render(SDL_Renderer *renderer);

private:
    const int JOYSTICK_DEAD_ZONE = 1000;

    SDLContext *sdl;

    int joystick_x = 0;
    int joystick_y = 0;
};

#endif // GAME_HPP
