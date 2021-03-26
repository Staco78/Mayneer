#include "Block.h"


Block::Block(sf::Texture* texture, sf::Vector2i pos): sf::RectangleShape(sf::Vector2f(60, 60)) {
	setTexture(texture);
	Block::pos = pos;
	setPosition(pos.x * 60, pos.y * -60);
}

sf::Vector2i Block::getPosition() {
	return pos;
}

sf::Vector2f Block::getPixelPosition() {
	return sf::RectangleShape::getPosition();
}
