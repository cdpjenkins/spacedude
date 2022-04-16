#include <exception>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>


#include "SDLContext.hpp"

using namespace std;

const int WIDTH = 1280;
const int HEIGHT = 800;

static bool initGL()
{
    bool success = true;
    GLenum error = GL_NO_ERROR;

    GLuint vaoId = 0;

    // glEnable(GL_BLEND);
    // glEnable(GL_DEPTH_TEST);


    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    //Check for error
    error = glGetError();
    if( error != GL_NO_ERROR ) {
        printf( "Error initializing OpenGL! --->    %s<---\n", gluErrorString( error ) );
        throw exception();
    }

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Check for error
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        throw exception();
    }

    glViewport(0, 0, WIDTH, HEIGHT);
    //Initialize clear color
    glClearColor( 1.f, 0.f, 0.f, 1.f );
    
    //Check for error
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        throw exception();
    }

    return true;
}

SDLContext::SDLContext() {
    int rc = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    if (rc != 0) {
        throw exception();
    }

    //Use OpenGL 2.1
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    // SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


    cout << "Number of joysticks: " << SDL_NumJoysticks() << endl;
    if( SDL_NumJoysticks() < 1 )
    {
        printf( "Warning: No joysticks connected!\n" );
    } else {
        joystick = SDL_JoystickOpen(0);
        if( joystick == NULL )
        {
            printf( "Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError() );
            throw exception();
        }

        cout << "We operned joystick 1. It'd better work!!!1" << endl;
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
    SDL_Window *window = SDL_CreateWindow("Spacedude!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                        WIDTH, HEIGHT,
                                        SDL_WINDOW_OPENGL);
    if (window == NULL) {
        throw exception();
    }
    // // this doesn't work on Mac and I don't know why
    // SDL_RaiseWindow(window);
    // SDL_SetWindowInputFocus(window);

    gContext = SDL_GL_CreateContext(window);
    if (gContext == NULL) {
        throw exception();
    }



    if (SDL_GL_SetSwapInterval( 1 ) < 0) {
        printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
        throw exception();
    }

    //Initialize OpenGL
    if(!initGL())
    {
        printf( "Unable to initialize OpenGL!\n" );
        throw exception();
    }

    // renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // dude_texture = IMG_LoadTexture(renderer, "assets/dude.png");

    // asteroid128_texture = IMG_LoadTexture(renderer, "assets/asteroid128.png");
    // asteroid64_texture = IMG_LoadTexture(renderer, "assets/asteroid64.png");
    // asteroid32_texture = IMG_LoadTexture(renderer, "assets/asteroid32.png");
    // asteroid16_texture = IMG_LoadTexture(renderer, "assets/asteroid16.png");
    // asteroid8_texture = IMG_LoadTexture(renderer, "assets/asteroid8.png");

    // bullet_texture = IMG_LoadTexture(renderer, "assets/bullet.png");

    // SDL_UpdateWindowSurface(window);
}

SDLContext::~SDLContext() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_JoystickClose( joystick );
    SDL_Quit();
}
