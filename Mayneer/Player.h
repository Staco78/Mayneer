#pragma once
#include <SFML/Graphics.hpp> 
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "Blocks/Block.h"
#include "Utils.h"

class Player :
    public sf::RectangleShape
{
public:
    sf::RenderWindow* w;
    Player(sf::RenderWindow* w,sf::Vector2f pos = sf::Vector2f(0, 0), std::vector<Block>* blocks = 0);
    void moveRight();
    void moveLeft();
    void update();
    void fall();
    void jump();
    void idle();
    void setPosition(sf::Vector2f newPos);
    sf::Vector2f getPosition();
    sf::Vector2f getPixelPosition();
    sf::FloatRect getBounds();

private:
    sf::Vector2f move();
    bool canFall();

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
    std::vector<Block>* blocks;
};