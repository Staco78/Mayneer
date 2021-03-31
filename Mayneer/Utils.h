#pragma once

#include <SFML/System.hpp>
#include <string>

namespace Utils {
	static int blockSize = 60;
	sf::Vector2f blockToPixelPosition(sf::Vector2f pos);
	sf::Vector2f pixelToBlockPosition(sf::Vector2f pos);
}
