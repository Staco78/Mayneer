#include "Game.h"

using namespace std;

Game::Game(int w, int h, sf::Uint32 style): player(sf::Vector2f(-1, 0), &visibleBlocks), map(&visibleBlocks, &player)
{
    windowVideoMode = sf::VideoMode(w, h);
    windowStyle = style;
    map.setRenderDistance(sf::Vector2u(10, 10));
    for (int i = 0; i < 100; i++) {
        map.addBlock(Blocks::Block1(&textures.block1, sf::Vector2i(i*3, i*2)));
   }
}


void Game::start()
{
    sf::RenderWindow window(windowVideoMode, "Mayneer", windowStyle);
    window.setFramerateLimit(60);

    sf::View view(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(window.getSize()));

    sf::Font font;
    font.loadFromFile("assets/fonts/arial.ttf");

    sf::Text textFPS;
    textFPS.setFont(font);
    textFPS.setCharacterSize(16);

    sf::Text textPos;
    textPos.setFont(font);
    textPos.setCharacterSize(16);
    textPos.setPosition(0, 20);

    bool debug = true;

    float fps = 0;
    
    sf::Clock fpsClock;
    int clockReadableText = 0;
    int clockDelayKey = 0;

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
                player.moveRight();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                player.moveLeft();
            }
            else {
                player.idle();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                player.jump();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3) && clockDelayKey > 12) {
                clockDelayKey = 0;
                debug = !debug;
            }
        }


        map.update();
        player.update();
        window.clear();
        view.setCenter(player.getPixelPosition());
        window.setView(view);
        for (int i = 0; i < visibleBlocks.size(); i++) {
            if (visibleBlocks[i].isVisible())
                window.draw(visibleBlocks[i]);
        }
        window.draw(player);
        if (clockReadableText == 5) {
            clockReadableText = 0;
            textFPS.setString(std::to_string(int(round(fps))) + " fps");
            textPos.setString("X: " + std::to_string(player.getPosition().x) + " Y: " + std::to_string(player.getPosition().y));
        }
        window.setView(window.getDefaultView());

        // draw static shapes

        if (debug) {
            window.draw(textFPS);
            window.draw(textPos);
        }


        window.setView(view);
        window.display();

        clockReadableText++;
        clockDelayKey++;
        fps = 1 / fpsClock.getElapsedTime().asSeconds();
        fpsClock.restart();
        
    }
}

void Game::loadTexture() {
    textures.load();
}