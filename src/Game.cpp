#include "Game.hpp"
#include <SDL3_image/SDL_image.h>
#include <ctime>


Game::Game() {

}

Game::~Game() {


}

void Game::init(const char *title, int xpos, int ypos, int width, int height) {
    srand(time(NULL));
    isOnIsland = false;
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

        /* PLAYER TEXTURES NORMAL */
        playerUp = IMG_LoadTexture(renderer, "../assets/player_up.png");
        playerDown = IMG_LoadTexture(renderer, "../assets/player_down.png");
        playerLeft = IMG_LoadTexture(renderer, "../assets/player_left.png");
        playerRight = IMG_LoadTexture(renderer, "../assets/player_right.png");

        /* PLAYER TEXTURES BOAT */
        playerBoatUp = IMG_LoadTexture(renderer, "../assets/player_boat_up.png");
        playerBoatDown = IMG_LoadTexture(renderer, "../assets/player_boat_down.png");
        playerBoatLeft = IMG_LoadTexture(renderer, "../assets/player_boat_left.png");
        playerBoatRight = IMG_LoadTexture(renderer, "../assets/player_boat_right.png");

        currentPlayerTexture = playerDown;
        
        playerDest.x = 100;
        playerDest.y = 100;
        playerDest.w = 42;
        playerDest.h = 42;

        backgroundTexture = IMG_LoadTexture(renderer, "../assets/background.png");

        islandSurface = IMG_Load("../assets/island.png");
        islandTexture = SDL_CreateTextureFromSurface(renderer, islandSurface);
        islandDest.x = 500;
        islandDest.y = 300;
        islandDest.w = 600;
        islandDest.h = 300;

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
bool isPixelSolid(SDL_Surface* surface, float x, float y, SDL_FRect destRect) {

    int localX = (int)((x - destRect.x) * (surface->w / destRect.w));
    int localY = (int)((y - destRect.y) * (surface->h / destRect.h));

    if (localX < 0 || localY < 0 || localX >= surface->w || localY >= surface->h) {
        return false;
    }

    uint32_t* pixels = (uint32_t*)surface->pixels;
    uint32_t pixel = pixels[(localY * surface->w) + localX];
    
    uint8_t r, g, b, a;
    SDL_GetRGBA(pixel, SDL_GetPixelFormatDetails(surface->format), NULL, &r, &g, &b, &a);

    return (a > 10);
}

void Game::update() {
    uint64_t now = SDL_GetTicks();

    deltaTime = (now-lastTime) / 1000.0f;
    lastTime = now;

    if (deltaTime > 0.1f) deltaTime = 0.1f;

    const bool *state = SDL_GetKeyboardState(NULL);

    float speed = 300.0f;


    if (state[SDL_SCANCODE_W]) {
        if (playerDest.y > 0) playerDest.y -= speed * deltaTime;
        if (!isOnIsland) {
            currentPlayerTexture = playerBoatUp;
        } else {
            currentPlayerTexture = playerUp;
        }
    }
    if (state[SDL_SCANCODE_S]) {
        if (playerDest.y < 694) playerDest.y += speed * deltaTime;
        if (!isOnIsland) {
            currentPlayerTexture = playerBoatDown;
        } else {
            currentPlayerTexture = playerDown;
        }
    }

    if (state[SDL_SCANCODE_A]) {
        if (playerDest.x > 0) playerDest.x -= speed * deltaTime;
        if (!isOnIsland) {
            currentPlayerTexture = playerBoatLeft;
        } else {
            currentPlayerTexture = playerLeft;
        }
    }
    if (state[SDL_SCANCODE_D]) {
        if (playerDest.x < 1254) playerDest.x += speed * deltaTime;
        if (!isOnIsland) {
            currentPlayerTexture = playerBoatRight;
        } else {
            currentPlayerTexture = playerRight;
        }
        
    }   
    float playerCenterX = playerDest.x + (playerDest.w / 2.0f);
    float playerCenterY = playerDest.y + (playerDest.h / 2.0f);

    if (isPixelSolid(islandSurface, playerCenterX, playerCenterY, islandDest)) {
        isOnIsland = true;
    } else {
        isOnIsland = false;
    }

    std::cout << isOnIsland << std::endl;
    
    
}

void Game::render() {
    
    SDL_SetRenderDrawColorFloat(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, backgroundTexture, NULL, NULL);
    SDL_RenderTexture(renderer, islandTexture, NULL, &islandDest);
    SDL_RenderTexture(renderer, currentPlayerTexture, NULL, &playerDest);
    SDL_RenderPresent(renderer);

}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroySurface(islandSurface);
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(playerLeft);
    SDL_DestroyTexture(playerRight);
    SDL_DestroyTexture(playerUp);
    SDL_DestroyTexture(playerDown);
    SDL_DestroyTexture(playerBoatLeft);
    SDL_DestroyTexture(playerBoatRight);
    SDL_DestroyTexture(playerBoatUp);
    SDL_DestroyTexture(playerBoatDown);

    SDL_Quit();

    std::cout << "Game cleaned";
}
