#include "Player.h"

Player::Player(sf::Vector2f pos) : sf::RectangleShape(sf::Vector2f(150, 111)) {
	setPosition(pos);
	texture0.loadFromFile("assets/player/idle-00.png");
	texture1.loadFromFile("assets/player/idle-01.png");
	texture2.loadFromFile("assets/player/idle-02.png");
	actualTexture.loadFromImage(texture0);
	setTexture(&actualTexture);
}

sf::Vector2f Player::move(sf::Vector2f movement) {
	setPosition(getPosition() + movement);
	return getPosition();
}

sf::Vector2f Player::move(float x, float y) {
	setPosition(getPosition() + sf::Vector2f(x, y));
	return getPosition();
}

void Player::nextTexture() {
	if (nTexture == 0) {
		actualTexture.loadFromImage(texture1);
		nTexture = 1;
	}
	else if (nTexture == 1) {
		actualTexture.loadFromImage(texture2);
		nTexture = 2;
	}
	else if (nTexture == 2) {
		actualTexture.loadFromImage(texture0);
		nTexture = 0;
	}
}

void Player::update() {
	move(speed);
}

void Player::fall(float G) {
	move(0, G);
}