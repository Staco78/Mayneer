#include "Game.h"

using namespace std;

Game::Game(int w, int h, sf::Uint32 style)
{
    windowVideoMode = sf::VideoMode(w, h);
    windowStyle = style;
    player = new Player(sf::Vector2f(0, 0));
}

void Game::start()
{
    sf::RenderWindow window(windowVideoMode, "Mayneer", windowStyle);
    window.setFramerateLimit(60);

    sf::View view(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(window.getSize()));
    player->setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2) - sf::Vector2f(player->getSize().x / 2, player->getSize().y / 2));

    int clock2 = 0;

    std::vector<Block1> v;
    for (int i = 0; i < 1000; i++) {
        v.push_back(Block1(&textureBlock1));
        v.back().setPosition(i * 10, i* 10);
    }

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
                player->move(10, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                player->move(-10, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                player->move(0, -10);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                player->move(0, 10);
            }
        }

        //clocks

        if (clock2 == 30)
        {
            clock2 = 0;
            player->nextTexture();
        }

        player->fall(1);

        player->update();

        view.setCenter(player->getPosition() + sf::Vector2f(player->getSize().x / 2, player->getSize().y / 2));
        window.setView(view);
        window.clear();
        for (int i = 0; i < v.size(); i++) {
            window.draw(v[i]);
        }
        window.draw(*player);
        window.display();
        clock2++;
    }

    delete player;
}


void Game::initTexture() {
    textureBlock1.loadFromFile("assets/block1.png");
}