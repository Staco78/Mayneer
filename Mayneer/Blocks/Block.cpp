#include "Block.h"
namespace Blocks{


Block::Block(sf::Texture* texture, sf::Vector2i pos) : sf::RectangleShape(sf::Vector2f(60, 60)) {
	setTexture(texture);
	Block::pos = pos;
	setPosition(Utils::blockToPixelPosition(sf::Vector2f(pos)));
}

Block::Block(sf::Vector2i pos) : sf::RectangleShape(sf::Vector2f(60, 60)) {
	Block::pos = pos;
	setPosition(Utils::blockToPixelPosition(sf::Vector2f(pos)));
}

Block::Block() : sf::RectangleShape(sf::Vector2f(60, 60)) {}

sf::Vector2i Block::getPosition() {
	return pos;
}

sf::Vector2f Block::getPixelPosition() {
	return sf::RectangleShape::getPosition();
}


sf::FloatRect Block::getBounds() {
	return sf::FloatRect(pos.x, pos.y, 1, -1);
}

bool Block::operator==(Block block1)
{
	return getPosition() == block1.getPosition();
}

bool Block::isSolid() { return solid; }
bool Block::isVisible() { return visible; }

}

