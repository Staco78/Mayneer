#pragma once

#include <iostream>

#include "Block.h"

class Block1: public Block
{
public:
	Block1(sf::Texture* texture, sf::Vector2i pos);
};