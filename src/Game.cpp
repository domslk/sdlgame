#include "Game.hpp"
#include <SDL3_image/SDL_image.h>
Game::Game() {

}

Game::~Game() {


}

void Game::init(const char *title, int xpos, int ypos, int width, int height) {

    if (SDL_Init(SDL_INIT_VIDEO)) {
        window = SDL_CreateWindow(title, width, height, 0);
        if (!window) {
            std::cout << "Problem initializing window!\n";
            return;
        }

        renderer = SDL_CreateRenderer(window, NULL);
        SDL_SetRenderVSync(renderer, 1);
        if (!renderer) {
            std::cout << "Problem initializing renderer!\n";
            return;
        }

        playerTexture = IMG_LoadTexture(renderer, "../assets/player.png");
        playerDest.x = 100;
        playerDest.y = 100;
        playerDest.w = 36;
        playerDest.h = 36;


        isRunning = true;
    } else {
        std::cout << "fruick";
        isRunning = false;
    }
    
}

void Game::handleEvents() {
    SDL_Event event;

    
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT: 
                isRunning = false;
                break;

            default:
                break;
        }
    }
    
    
}

void Game::update() {
    uint64_t now = SDL_GetTicks();

    deltaTime = (now-lastTime) / 1000.0f;
    lastTime = now;

    if (deltaTime > 0.1f) deltaTime = 0.1f;

    const bool *state = SDL_GetKeyboardState(NULL);

    float speed = 300.0f;

    if (state[SDL_SCANCODE_W]) playerDest.y -= speed * deltaTime;
    if (state[SDL_SCANCODE_S]) playerDest.y += speed * deltaTime;
    if (state[SDL_SCANCODE_A]) playerDest.x -= speed * deltaTime;
    if (state[SDL_SCANCODE_D]) playerDest.x += speed * deltaTime;
}

void Game::render() {
    
    SDL_SetRenderDrawColorFloat(renderer, 1, 0, 0, 1);
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, playerTexture,NULL, &playerDest);
    SDL_RenderPresent(renderer);

}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game cleaned";
}
