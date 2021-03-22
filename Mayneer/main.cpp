#include "Game.h"
#include <SFML/System.hpp>

using namespace std;

int main() {
    Game game(500, 500, sf::Style::Default);
    game.start();
    #ifdef NDEBUG
        // nondebug
    #else
        // debug code
        system("pause");
    #endif
    return 0;
}