#ifndef GAME_HPP
#define GAME_HPP

#include <list>

#include "Player.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "SDLContext.hpp"

using namespace std;

class Game {
public:
    explicit Game(SDLContext *sdl);
    ~Game();

    unique_ptr<Player> dude = {};
    list<unique_ptr<Entity>> entities = {};

    void main_loop();
    void render(SDL_Renderer *renderer);

private:
    const int JOYSTICK_DEAD_ZONE = 1000;

    SDLContext *sdl;

    int joystick_x = 0;
    int joystick_y = 0;

    void cull_dead_entities();

    bool handle_sdl_events(bool *keys, SDL_Event &e);
};

#endif // GAME_HPP
