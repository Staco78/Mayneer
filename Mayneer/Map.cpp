#include "Map.h"

Map::Map(std::vector<Blocks::Block>* visibleBlocks, Player* player) {
	Map::visibleBlocks = visibleBlocks;
	Map::player = player;

}

void Map::update() {
	/*visibleBlocks->clear();
	for (int i = 0; i < blocks.size(); i++) {
		for (int j = 0; j < blocks[i].size(); j++)
			visibleBlocks->push_back(blocks[i][j]);
	}*/
	/*for (int i = 0; i < visibleBlocks->size(); i++) {
		if (!(visibleBlocks->at(i).getPosition().x >= round(player->getPosition().x) - renderDistance.x && visibleBlocks->at(i).getPosition().x <= round(player->getPosition().x) + renderDistance.x) || !(visibleBlocks->at(i).getPosition().y >= round(player->getPosition().y) - renderDistance.y && visibleBlocks->at(i).getPosition().y <= round(player->getPosition().y) + renderDistance.y)) {
			visibleBlocks->erase(visibleBlocks->begin() + i);
		}
	}*/

	visibleBlocks->clear();

	for (int x = 0; x < blocks.size(); x++) {
		for (int y = 0; y < blocks[x].size(); y++) {
			if ((blocks[x][y].getPosition().x >= round(player->getPosition().x) - renderDistance.x && blocks[x][y].getPosition().x <= round(player->getPosition().x) + renderDistance.x) && (blocks[x][y].getPosition().y >= round(player->getPosition().y) - renderDistance.y && blocks[x][y].getPosition().y <= round(player->getPosition().y) + renderDistance.y)) {
				if (blocks[x][y].isSolid() || blocks[x][y].isVisible())
					visibleBlocks->push_back(blocks[x][y]);
			}
		}
	}
}

void Map::addBlocks(std::vector<Blocks::Block> newBlocks) {
	for (int i = 0; i < newBlocks.size(); i++) {
		blocks[newBlocks[i].getPosition().x][newBlocks[i].getPosition().y] = newBlocks[i];
	}
}

void Map::addBlock(Blocks::Block block) {
	//std::cout << blocks.size() << "\t" << block.getPosition().x << ":" << block.getPosition().y << std::endl;
	if (blocks.size() < block.getPosition().x + 1)
		blocks.resize(block.getPosition().x + 1);
	
	while (blocks[block.getPosition().x].size() < block.getPosition().y) {
		blocks[block.getPosition().x].push_back(Blocks::Air(sf::Vector2i(block.getPosition().x, blocks[block.getPosition().x].size())));
	}
	
	if (blocks[block.getPosition().x].size() == block.getPosition().y)
		blocks[block.getPosition().x].push_back(block);
	else
		blocks[block.getPosition().x][block.getPosition().y] = block;
	
		
		
	/*while (blocks.size() < block.getPosition().x + 1) {
		std::vector<Blocks::Block> t;
		blocks.push_back(t);
		std::cout << blocks.si
	 }*/
	 /*
	while (blocks[block.getPosition().x].size() < block.getPosition().y) {
		Blocks::Air t;
		blocks[block.getPosition().x].push_back(t);
	}*/
}

void Map::setRenderDistance(sf::Vector2u newRenderDistance) {
	renderDistance = newRenderDistance;
}

sf::Vector2u Map::getRenderDistance() { return renderDistance; }