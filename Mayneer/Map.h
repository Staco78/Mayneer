#pragma once
#include "Blocks.h"
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Player.h"
#include <cmath>
#include <iostream>

class Map
{
public:
	Map(std::vector<Blocks::Block>* visibleBlocks, Player* player);
	void update();
	void setRenderDistance(sf::Vector2u newRenderDistance);
	sf::Vector2u getRenderDistance();

	void addBlocks(std::vector <Blocks::Block > newBlocks);
	void addBlock(Blocks::Block block);
private:
	std::vector<Blocks::Block>* visibleBlocks;
	std::vector<std::vector<Blocks::Block>> blocks;

	Player* player;

	sf::Vector2u renderDistance;
};

