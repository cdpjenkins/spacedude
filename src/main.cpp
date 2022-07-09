#include <iostream>
#include <cmath>
#include <SDL.h>
#include <SDL_image.h>

#include "Dude.hpp"
#include "SDLContext.hpp"
#include "Game.hpp"

using namespace std;

SDL_Texture *dude_texture;

int main(int argc, char** argv) {
    SDLContext sdl = SDLContext();

    Game game = Game(&sdl);

    game.main_loop();

    return 0;
}
