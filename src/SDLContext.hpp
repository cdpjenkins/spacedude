#ifndef SDL_CONTEXT_HPP
#define SDL_CONTEXT_HPP

#include <vector>

#include <SDL2/SDL.h>

using namespace std;

enum TextureID {
    DUDE_TEXTURE,
    ASTEROID_128_TEXTURE,
    ASTEROID_64_TEXTURE,
    ASTEROID_32_TEXTURE,
    ASTEROID_16_TEXTURE,
    ASTEROID_8_TEXTURE,
    BULLET_TEXTURE,
    NUM_TEXTURES
};

class SDLContext {
public:
    SDLContext();
    ~SDLContext();

    // this is the wrong place for this
    SDL_Texture *dude_texture = NULL;

    SDL_Texture *asteroid128_texture = NULL;
    SDL_Texture *asteroid64_texture = NULL;
    SDL_Texture *asteroid32_texture = NULL;
    SDL_Texture *asteroid16_texture = NULL;
    SDL_Texture *asteroid8_texture = NULL;

    SDL_Texture *bullet_texture = NULL;
    
    SDL_Renderer *renderer = NULL;

    SDL_Texture* textures[NUM_TEXTURES];

private:
    SDL_Joystick* joystick = NULL;
    SDL_Window *window = NULL;
};

#endif // SDL_CONTEXT_HPP
