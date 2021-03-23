#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Player.h"
#include "Blocks/Block1.h"

class Game
{
public:
	Game(int w, int h, sf::Uint32 style);
	void start();
	void initTexture();
private:
	sf::VideoMode windowVideoMode;
	sf::Uint32 windowStyle;
	Player* player = 0;

	sf::Texture textureBlock1;
};