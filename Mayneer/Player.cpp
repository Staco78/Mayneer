#include "Player.h"

Player::Player(sf::Vector2f pos) : sf::RectangleShape(sf::Vector2f(150, 111)) {
	setPosition(pos);
	setOrigin(getSize().x / 2, getSize().y);
	textureIddle0.loadFromFile("assets/player/idle-00.png");
	textureIddle1.loadFromFile("assets/player/idle-01.png");
	textureIddle2.loadFromFile("assets/player/idle-02.png");
	textureRun0.loadFromFile("assets/player/run-00.png");
	textureRun1.loadFromFile("assets/player/run-01.png");
	textureRun2.loadFromFile("assets/player/run-02.png");
	textureRun3.loadFromFile("assets/player/run-03.png");
	textureRun4.loadFromFile("assets/player/run-04.png");
	textureRun5.loadFromFile("assets/player/run-05.png");
	actualTexture.loadFromImage(textureIddle0);
	setTexture(&actualTexture);
	update();
}

void Player::setPosition(sf::Vector2f newPos) {
	if (newPos.y >= 0)
		pos = newPos;
	else
		pos = sf::Vector2f(newPos.x, 0);
}

sf::Vector2f Player::getPosition() { return pos; }
sf::Vector2f Player::getPixelPosition() { return sf::RectangleShape::getPosition(); }


sf::Vector2f Player::move(sf::Vector2f movement) {
	setPosition(pos + movement);
	return getPosition();
}

sf::Vector2f Player::move(float x, float y) {
	setPosition(pos + sf::Vector2f(x, y));
	return getPosition();
}

void Player::moveRight() {
	speed.x = 1;
}

void Player::moveLeft() {
	speed.x = -1;
}

void Player::idle() {
	speed.x = 0;
}

void Player::update() {
	move(speed);
	animationClock++;
	if (speed.x != 0) {
		if (nTexture != "r0" && nTexture != "r1" && nTexture != "r2" && nTexture != "r3" && nTexture != "r4" & nTexture != "r5") {
			animationClock = 0;
			nTexture = "r0";
			actualTexture.loadFromImage(textureRun0);
		}
		else if (animationClock == 10) {
			animationClock = 0;
			if (nTexture == "r0") {
				actualTexture.loadFromImage(textureRun1);
				nTexture = "r1";
			}
			else if (nTexture == "r1") {
				actualTexture.loadFromImage(textureRun2);
				nTexture = "r2";
			}
			else if (nTexture == "r2") {
				actualTexture.loadFromImage(textureRun3);
				nTexture = "r3";
			}
			else if (nTexture == "r3") {
				actualTexture.loadFromImage(textureRun4);
				nTexture = "r4";
			}
			else if (nTexture == "r4") {
				actualTexture.loadFromImage(textureRun5);
				nTexture = "r5";
			}
			else if (nTexture == "r5") {
				actualTexture.loadFromImage(textureRun0);
				nTexture = "r0";
			}
		}
		if (speed.x > 0) {
			//right
			setScale(1.f, 1.f);
		}
		else {
			//left
			setScale(-1.f, 1.f);
		}
	}
	else {
		if (nTexture != "i0" && nTexture != "i1" && nTexture != "i2") {
			animationClock = 0;
			nTexture = "i0";
			actualTexture.loadFromImage(textureIddle0);
		}
		else if (animationClock == 15) {
			animationClock = 0;
			if (nTexture == "i0") {
				actualTexture.loadFromImage(textureIddle1);
				nTexture = "i1";
			}
			else if (nTexture == "i1") {
				actualTexture.loadFromImage(textureIddle2);
				nTexture = "i2";
			}
			else if (nTexture == "i2") {
				actualTexture.loadFromImage(textureIddle0);
				nTexture = "i0";
			}
		}
	}
	sf::RectangleShape::setPosition(pos.x * 10, pos.y * -10);
	std::cout << pos.x << ":" << pos.y << "\t" << speed.x << ":" << speed.y << "\t" << animationClock << "\t" << nTexture << "\n";
}

void Player::fall() {
	if (pos.y > 0)
		speed.y += -0.05;
	else if (speed.y < 0)
		speed.y = 0;
}

void Player::jump() {
	if (speed.y == 0)
		speed.y = 1;
}