#include "Game.hpp"

Game::Game() {

}

Game::~Game() {


}

void Game::init(const char *title, int xpos, int ypos, int width, int height) {
    window = SDL_CreateWindow(title, width, height, 0);
    if (!window) {
        std::cout << "Problem initializing window!\n";
        return;
    }

    renderer = SDL_CreateRenderer(window, title);

    if (!renderer) {
        std::cout << "Problem initializing renderer!\n";
        return;
    }
    isRunning = true;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_EVENT_QUIT: 
            isRunning = false;
            break;

        default:
            break;
    }
}

void Game::update() {

}

void Game::render() {
    
    SDL_SetRenderDrawColorFloat(renderer, 1, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game cleaned";
}
