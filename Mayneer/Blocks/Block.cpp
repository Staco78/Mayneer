#include "Block.h"

Block::Block(sf::Texture* texture): sf::RectangleShape(sf::Vector2f(10, 10)) {
	setTexture(texture);
}