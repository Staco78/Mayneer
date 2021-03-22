#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
public:
	Game(int w, int h, sf::Uint32 style);
	void start();
private:
	sf::VideoMode windowVideoMode;
	sf::Uint32 windowStyle;
	Player* player;
};

