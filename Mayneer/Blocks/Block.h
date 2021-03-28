#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils.h"

class Block: public sf::RectangleShape
{
public:
	Block(sf::Texture* texture, sf::Vector2i pos);
	sf::Vector2i getPosition();
	sf::Vector2f getPixelPosition();
	sf::FloatRect getBounds();
private:
	sf::Vector2i pos;
};

