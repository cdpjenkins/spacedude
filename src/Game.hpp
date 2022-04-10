#ifndef GAME_HPP
#define GAME_HPP

#include <list>

#include "Dude.hpp"
#include "Asteroid.hpp"
#include "SDLContext.hpp"

using namespace std;

class Game {
public:
    Game(SDLContext *sdl);

    Dude dude = Dude(400, 400, 0);
    list<Asteroid*> asteroids = list<Asteroid*>();

    void main_loop();
    void render(SDL_Renderer *renderer);

private:
    const int JOYSTICK_DEAD_ZONE = 1000;

    SDLContext *sdl;

    int joystick_x = 0;
    int joystick_y = 0;
};

#endif // GAME_HPP
