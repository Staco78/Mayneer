#pragma once
#include <SFML/Graphics.hpp> 

class Player :
    public sf::RectangleShape
{
public:
    Player(sf::Vector2f pos);
    sf::Vector2f move(sf::Vector2f movement);
    sf::Vector2f move(float x, float y);
    void nextTexture();
    void update();
    void fall(float G);
private:
    sf::Texture actualTexture;
    sf::Image texture0;
    sf::Image texture1;
    sf::Image texture2;
    int nTexture = 0;

    sf::Vector2f speed;
};