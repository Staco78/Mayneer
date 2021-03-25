#pragma once
#include <SFML/Graphics.hpp> 
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "Blocks/Block.h"

class Player :
    public sf::RectangleShape
{
public:
    Player(sf::Vector2f pos = sf::Vector2f(0, 0));
    void moveRight();
    void moveLeft();
    void update(std::vector<Block>* blocks);
    void fall();
    void jump();
    void idle();
    void setPosition(sf::Vector2f newPos);
    sf::Vector2f getPosition();
    sf::Vector2f getPixelPosition();

private:
    sf::Vector2f move(sf::Vector2f movement, std::vector<Block>* blocks);
    bool collisionRight(float V, std::vector<Block>* block);
    bool collisionLeft(float V, std::vector<Block>* block);
    bool collisionUp(float V, std::vector<Block>* block);
    bool collisionDown(float V, std::vector<Block>* block);

    sf::Vector2f pos;
    sf::Texture actualTexture;
    sf::Image textureIddle0;
    sf::Image textureIddle1;
    sf::Image textureIddle2;
    sf::Image textureRun0;
    sf::Image textureRun1;
    sf::Image textureRun2;
    sf::Image textureRun3;
    sf::Image textureRun4;
    sf::Image textureRun5;
    sf::Image textureJump0;
    sf::Image textureJump1;
    sf::Image textureFall0;
    sf::Image textureFall1;

    std::string nTexture = "i0";
    int animationClock = 0;

    sf::Vector2f speed;

};