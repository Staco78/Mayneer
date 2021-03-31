#include "Air.h"

namespace Blocks {
	Air::Air() : Block() {
		solid = false;
		visible = false;
		name = "air";
	}

	Air::Air(sf::Vector2i pos) : Block(pos) {
		solid = false;
		name = "air";
		visible = false;
	}		
}