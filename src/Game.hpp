#ifndef Game_hpp
#define Game_hpp

#include "SDL3/SDL.h"
//#include <SDL3_image/SDL_image.h>

#include <iostream>

class Game {
    int count = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Texture *playerTexture;
    SDL_FRect playerDest;

    uint64_t lastTime;
    float deltaTime;        
    public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running () {
        return isRunning;
    }


};

#endif