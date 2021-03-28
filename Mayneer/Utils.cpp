#include "Utils.h"

namespace Utils {
	sf::Vector2f blockToPixelPosition(sf::Vector2f pos) {
		return sf::Vector2f(pos.x * blockSize, pos.y * -blockSize);
	}

	sf::Vector2f pixelToBlockPosition(sf::Vector2f pos) {
		return sf::Vector2f(pos.x / blockSize, pos.y / -blockSize);
	}
}