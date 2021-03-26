#pragma once
#include <SFML/Graphics.hpp>

class Block: public sf::RectangleShape
{
public:
	Block(sf::Texture* texture, sf::Vector2i pos);
	sf::Vector2i getPosition();
	sf::Vector2f getPixelPosition();
private:
	sf::Vector2i pos;
};

