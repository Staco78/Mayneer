#pragma once
#include "Block.h"

namespace Blocks {
    class Air :
        public Block
    {
    public:
        Air();
        Air(sf::Vector2i pos);
    };

}
