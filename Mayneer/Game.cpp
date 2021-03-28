#include "Game.h"

using namespace std;

Game::Game(int w, int h, sf::Uint32 style)
{
    windowVideoMode = sf::VideoMode(w, h);
    windowStyle = style;
}

void Game::start()
{
    sf::RenderWindow window(windowVideoMode, "Mayneer", windowStyle);
    window.setFramerateLimit(60);

    sf::View view(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(window.getSize()));
    player = new Player(&window, sf::Vector2f(0, 20), &visibleBlocks);


    for (int i = 0; i < 1000; i++) {
        visibleBlocks.push_back(Block1(&textureBlock1, sf::Vector2i(i, 1)));
    }
    for (int i = 0; i < 20; i++) {
        visibleBlocks.push_back(Block1(&textureBlock1, sf::Vector2i(i + 10, i)));
    }
    for (int i = 0; i < 3; i++) {
        visibleBlocks.push_back(Block1(&textureBlock1, sf::Vector2i(-20, i)));
    }
    for (int i = 0; i < 5; i++) {
        visibleBlocks.push_back(Block1(&textureBlock1, sf::Vector2i(-21, i)));
    }
    

    float fps = 0;
    
    sf::Clock fpsClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (window.hasFocus())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                player->moveRight();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                player->moveLeft();
            }
            else {
                player->idle();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                player->jump();
            }
        }

        window.clear();

        view.setCenter(player->getPixelPosition());
        window.setView(view);
        for (int i = 0; i < visibleBlocks.size(); i++) {
            window.draw(visibleBlocks[i]);
        }
        player->update();

        window.draw(*player);
        window.display();

        fps = 1 / fpsClock.getElapsedTime().asSeconds();
        cout << fps << "\t";
        fpsClock.restart();
        
    }

    delete player;
}


void Game::initTexture() {
    textureBlock1.loadFromFile("assets/block1.png");
}