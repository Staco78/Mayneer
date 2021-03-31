#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils.h"

namespace Blocks {
	class Block : public sf::RectangleShape
	{
	public:
		Block();
		Block(sf::Vector2i pos);
		Block(sf::Texture* texture, sf::Vector2i pos);
		sf::Vector2i getPosition();
		sf::Vector2f getPixelPosition();
		sf::FloatRect getBounds();
		bool operator==(Block block1);
		bool isSolid();
		bool isVisible();
	protected:
		sf::Vector2i pos;
		std::string name;
		bool solid = true;
		bool visible = true;
	};

}
