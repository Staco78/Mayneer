#include "Player.h"

double round(double value) {
	return floor(value + 0.5);
}

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
	textureJump0.loadFromFile("assets/player/jump-02.png");
	textureJump1.loadFromFile("assets/player/jump-03.png");
	textureFall0.loadFromFile("assets/player/fall-00.png");
	textureFall1.loadFromFile("assets/player/fall-01.png");
	actualTexture.loadFromImage(textureIddle0);
	setTexture(&actualTexture, true);
}

void Player::setPosition(sf::Vector2f newPos) {
	if (newPos.y >= 0)
		pos = newPos;
	else
		pos = sf::Vector2f(newPos.x, 0);
}

sf::Vector2f Player::getPosition() { return pos; }
sf::Vector2f Player::getPixelPosition() { return sf::RectangleShape::getPosition(); }


sf::Vector2f Player::move(sf::Vector2f movement, std::vector<Block>* blocks) {
	if (movement.x > 0) {
		if (!collisionRight(movement.x, blocks))
			setPosition(getPosition() + sf::Vector2f(movement.x, 0));
	}
	else if (movement.x < 0) {
		if (!collisionLeft(movement.x, blocks))
			setPosition(getPosition() + sf::Vector2f(movement.x, 0));
	}
	if (movement.y > 0) {
		if (!collisionUp(movement.y, blocks))
			setPosition(getPosition() + sf::Vector2f(0, movement.y));
	}
	else if (movement.y < 0) {
		if (!collisionDown(movement.y, blocks))
			setPosition(getPosition() + sf::Vector2f(0, movement.y));
	}
	return getPosition();
}


bool Player::collisionRight(float V, std::vector<Block>* blocks) {
	
	return false;
}

bool Player::collisionLeft(float V, std::vector<Block>* blocks) {

	return false;
}

bool Player::collisionUp(float V, std::vector<Block>* blocks) {

	return false;
}

bool Player::collisionDown(float V, std::vector<Block>* blocks) {
	for (int i = 0; i < blocks->size(); i++) {
		Block* block = &blocks->at(i);
		if (round(pos.x) == block->getPosition().x) {
			if (getGlobalBounds().intersects(block->getGlobalBounds()))
				return true;
		}
	}
	return false;
}

void Player::moveRight() {
	speed.x = 0.2;
}

void Player::moveLeft() {
	speed.x = -0.2;
}

void Player::idle() {
	speed.x = 0;
}

void Player::update(std::vector<Block>* blocks) {
	move(speed, blocks);
	animationClock++;
	if (speed.y > 0) {
		if (nTexture != "j0" && nTexture != "j1" && nTexture != "j2" && nTexture != "j3") {
			animationClock = 0;
			nTexture = "j0";
			actualTexture.loadFromImage(textureJump0);
		}
		else if (animationClock == 10) {
			animationClock = 0;
			if (nTexture == "j0") {
				actualTexture.loadFromImage(textureJump1);
				nTexture = "j1";
			}
			else if (nTexture == "j1") {
				actualTexture.loadFromImage(textureJump0);
				nTexture = "j0";
			}
		}
	}
	else if (speed.y < 0) {
		if (nTexture != "f0" && nTexture != "f1" && nTexture != "f2" && nTexture != "f3") {
			animationClock = 0;
			nTexture = "f0";
			actualTexture.loadFromImage(textureFall0);
		}
		else if (animationClock == 5) {
			animationClock = 0;
			if (nTexture == "f0") {
				actualTexture.loadFromImage(textureFall1);
				nTexture = "f1";
			}
			else if (nTexture == "f1") {
				actualTexture.loadFromImage(textureFall0);
				nTexture = "f0";
			}
		}
	}
	else if (speed.x != 0) {
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
	if (speed.x > 0) {
		//right
		setScale(1.f, 1.f);
	}
	else if (speed.x < 0) {
		//left
		setScale(-1.f, 1.f);
	}
	sf::RectangleShape::setPosition(pos.x * 60, pos.y * -60);
	//std::cout << pos.x << ":" << pos.y << "\t" << speed.x << ":" << speed.y << "\n";
}

void Player::fall() {
	if (pos.y > 0)
		speed.y += -0.01;
	else if (speed.y < 0)
		speed.y = 0;
}

void Player::jump() {
	if (speed.y == 0)
		speed.y = 0.2;
}