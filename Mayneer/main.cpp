#include "Game.h"
#include <SFML/System.hpp>

using namespace std;

int main() {
    Game game(500, 500, sf::Style::Default);
    game.loadTexture();
    game.start();
    #ifdef NDEBUG
    #else
        system("pause");
    #endif
    return 0;
}

