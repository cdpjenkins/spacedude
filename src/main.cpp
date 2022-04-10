#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Dude.hpp"
#include "SDLContext.hpp"
#include "Game.hpp"

using namespace std;

SDL_Texture *dude_texture;

int main(int argc, char** argv) {
    SDLContext sdl;
    Game game = Game(&sdl);

    game.main_loop();

    return 0;
}
