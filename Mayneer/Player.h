#pragma once
#include <SFML/Graphics.hpp> 
#include <iostream>
#include <string>
#include <cstdlib>

class Player :
    public sf::RectangleShape
{
public:
    Player(sf::Vector2f pos = sf::Vector2f(0, 0));
    void moveRight();
    void moveLeft();
    void update();
    void fall();
    void jump();
    void idle();
    void setPosition(sf::Vector2f newPos);
    sf::Vector2f getPosition();
    sf::Vector2f getPixelPosition();

private:
    sf::Vector2f move(sf::Vector2f movement);
    sf::Vector2f move(float x, float y);

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

    std::string nTexture = "i0";
    int animationClock = 0;

    sf::Vector2f speed;
};