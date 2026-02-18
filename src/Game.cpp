#include "Game.hpp"

Game::Game() {

}

Game::~Game() {


}

void Game::init(const char *title, int xpos, int ypos, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Everything initialized successfully.\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
        if (window) {
            std::cout << "Window created successfully!\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created successfully!\n";
        }
        isRunning = true;
    } else {
        isRunning = false;

    }


}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT: 
            isRunning = false;
            break;

        default:
            break;
    }
}

void Game::update() {


}

void Game::render() {
    SDL_RenderClear(renderer);
    // stuff to render

    SDL_RenderPresent(renderer);

}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game cleaned";
}
