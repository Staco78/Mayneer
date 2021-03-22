#pragma once
#include <SFML/Graphics.hpp> 

class Player :
    public sf::RectangleShape
{
public:
    Player(sf::Vector2f pos);
    sf::Vector2f move(sf::Vector2f movement);
    sf::Vector2f move(float x, float y);
private:
    sf::Texture texture;
};