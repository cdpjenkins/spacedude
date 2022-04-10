#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Dude.hpp"
#include "SDLContext.hpp"
#include "App.hpp"

using namespace std;

SDL_Texture *dude_texture;

int main(int argc, char** argv) {
    SDLContext sdl;
    App app = App(&sdl);

    app.main_loop();

    return 0;
}
