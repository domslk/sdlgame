#include "Game.hpp"


int main(int argc, const char *argv[]) {
    Game game = Game();
    game.init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);
    while (game.running()) {
        game.handleEvents();
        game.update();
        game.render();
        std::cout << "Running\n";
    }

    game.clean();
    return 0;
}