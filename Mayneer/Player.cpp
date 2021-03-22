#include "Player.h"

Player::Player(sf::Vector2f pos) : sf::RectangleShape(sf::Vector2f(100, 200)) {
	setPosition(pos);
	texture.loadFromFile("image.png");
	setTexture(&texture);
}

sf::Vector2f Player::move(sf::Vector2f movement) {
	setPosition(getPosition() + movement);
	return getPosition();
}

sf::Vector2f Player::move(float x, float y) {
	setPosition(getPosition() + sf::Vector2f(x, y));
	return getPosition();
}