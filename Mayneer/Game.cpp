#include "Game.h"

using namespace std;

Game::Game(int w, int h, sf::Uint32 style) {
	windowVideoMode = sf::VideoMode(w, h);
	windowStyle = style;
	player = new Player(sf::Vector2f(100, 100));
}

void Game::start() {
	sf::RenderWindow window(windowVideoMode, "Mayneer", windowStyle);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//actions


		//fin des actions

		window.clear();
		window.draw(*player);
		window.display();
	}

	delete player;

}