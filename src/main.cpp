#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

SDL_Texture *dude_texture;
int x = 500;
int y = 500;
float angle = 0;

void render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    int w, h;
    SDL_Rect dest = {.x = x, .y = y};
    
    dest.x -= (dest.w / 2);
	dest.y -= (dest.h / 2);

    SDL_QueryTexture(dude_texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopyEx(renderer, dude_texture, NULL, &dest, angle, NULL, SDL_FLIP_NONE);

    // SDL_RenderCopy(renderer, dude_texture, NULL, &dest);

    SDL_RenderPresent(renderer);
}

int main(int argc, char** argv) {
    int rc = SDL_Init(SDL_INIT_VIDEO);
    if (rc != 0) {
        throw exception();
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    SDL_Window *window = SDL_CreateWindow("Spacedude!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                        1280, 800,
                                        SDL_WINDOW_SHOWN | SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS);
    if (window == NULL) {
        throw exception();
    }

    // this doesn't work and I don't understand why
    SDL_RaiseWindow(window);
    SDL_SetWindowInputFocus(window);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    dude_texture = IMG_LoadTexture(renderer, "assets/dude.png");

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
                        case SDLK_UP:
                            y -= 5;
                            break;
                        case SDLK_DOWN:
                            y += 5;
                            break;
                        case SDLK_LEFT:
                            x -= 5;
                            break;
                        case SDLK_RIGHT:
                            x += 5;
                            break;
                        case SDLK_a:
                            angle -= 5;
                            break;
                        case SDLK_s:
                            angle += 5;
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
