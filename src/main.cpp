#include <iostream>
#ifdef _WIN32
#include <SDL/SDL.h> 
#else
#include <SDL2/SDL.h> 
#endif
#define WIDTH 800
#define HEIGHT 600
#define DELAY 3000

using namespace std;


int main(int argc, char* argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *player = NULL;

    bool running = true;


    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "SDL failed to initialize: " << SDL_GetError();
        return 1;
    }

    window = SDL_CreateWindow(
        "Game", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        WIDTH, 
        HEIGHT, 
        0
    );

    if (window == NULL) {
        cout << "SDL Failed to initialize" << SDL_GetError();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == NULL) {
        cout << "SDL failed to initialize renderer" << SDL_GetError();
        return 1;
    }
    while(running) {
        SDL_Event event;
        while (SDL_PollEvent(&event) == 1) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(renderer);
                SDL_Quit();
                running = false;
            }
            
        }
       
        
        

        

        SDL_RenderClear(renderer);
        
        SDL_Rect fillRect = { WIDTH / 4, HEIGHT / 4, WIDTH / 2, HEIGHT / 2 };
        //SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );        
        //SDL_RenderFillRect( renderer, &fillRect );
        SDL_SetRenderDrawColor(renderer, 0, 60, 128, 255);
        SDL_RenderPresent(renderer);
       
    }

    return 0;
}
