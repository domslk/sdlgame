#ifndef Game_hpp
#define Game_hpp

#include "SDL3/SDL.h"
//#include <SDL3_image/SDL_image.h>

#include <iostream>

class Game {
    int count = 0;
    bool isRunning;

    /* WINDOW */
    SDL_Window *window;
    SDL_Renderer *renderer;


    /* PLAYER */
    SDL_Texture* playerUp;
    SDL_Texture* playerDown;
    SDL_Texture* playerLeft;
    SDL_Texture* playerRight;

    SDL_Texture* playerBoatUp;
    SDL_Texture* playerBoatDown;
    SDL_Texture* playerBoatLeft;
    SDL_Texture* playerBoatRight;

    SDL_Texture* currentPlayerTexture;
    SDL_FRect playerDest;

    bool isOnIsland;


    /* GAME */
    SDL_Texture *backgroundTexture;

    SDL_Texture *islandTexture;
    SDL_Surface *islandSurface;
    SDL_FRect islandDest;

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