#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>


using namespace std;

void render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);
}

int main(int argc, char** argv) {

    int rc = SDL_Init(SDL_INIT_VIDEO);
    if (rc != 0) {
        throw exception();
    }

    SDL_Window *window = SDL_CreateWindow("Spacedude!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                        1280, 800,
                                        SDL_WINDOW_SHOWN | SDL_WINDOW_ALWAYS_ON_TOP);
    if (window == NULL) {
        throw exception();
    }

    // this doesn't work and I don't understand why
    SDL_RaiseWindow(window);
    SDL_SetWindowInputFocus(window);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            switch (e.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym) {
                        case SDLK_q:
                            quit = true;
                            break;
                    }
                    break;
            }
        }

        // Uint32 time_before_step = SDL_GetTicks();
        // grid.step();
        Uint32 time_after_step_before_draw = SDL_GetTicks();
        // cout << "Time to step: " << (time_after_step_before_draw - time_before_step) << endl;
        render(renderer);
        SDL_UpdateWindowSurface(window);
        Uint32 time_after_draw = SDL_GetTicks();
        // cout << "Time to draw: " << (time_after_draw - time_after_step_before_draw) << endl;
    }

    return 0;
}
