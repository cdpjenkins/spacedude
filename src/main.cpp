#include "SDLContext.hpp"
#include "Game.hpp"

using namespace std;

int main(int argc, char** argv) {
    SDLContext sdl = SDLContext();

    Game game = Game(&sdl);

    game.main_loop();

    return 0;
}
