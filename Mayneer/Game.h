#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Player.h"
#include "Blocks/Block1.h"
#include "Textures.h"
#include "Map.h"

class Game
{
public:
	Game(int w, int h, sf::Uint32 style);
	void start();
	void loadTexture();
private:
	sf::VideoMode windowVideoMode;
	sf::Uint32 windowStyle;
	Player player;
	Map map;


	std::vector<Blocks::Block> visibleBlocks;
	Textures textures;
};