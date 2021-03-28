#include "Block.h"


Block::Block(sf::Texture* texture, sf::Vector2i pos): sf::RectangleShape(sf::Vector2f(60, 60)) {
	setTexture(texture);
	Block::pos = pos;
	setPosition(Utils::blockToPixelPosition(sf::Vector2f(pos)));
}

sf::Vector2i Block::getPosition() {
	return pos;
}

sf::Vector2f Block::getPixelPosition() {
	return sf::RectangleShape::getPosition();
}


sf::FloatRect Block::getBounds() {
	return sf::FloatRect(pos.x, pos.y, 1, -1);
}