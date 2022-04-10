#ifndef APP_HPP
#define APP_HPP

#include "Dude.hpp"
#include "SDLContext.hpp"

class App {
public:
    App(SDLContext *sdl);

    Dude dude = Dude(500.0f, 500.0f, 0.0f);

    void main_loop();
    void render(SDL_Renderer *renderer);

private:
    const int JOYSTICK_DEAD_ZONE = 1000;

    SDLContext *sdl;

    int joystick_x = 0;
    int joystick_y = 0;
};

#endif // APP_HPP
