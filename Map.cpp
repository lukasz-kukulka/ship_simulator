#include "Map.hpp"

#include <algorithm>
#include <random>
#include <iostream>

Map::Map(std::pair<uint8_t, uint8_t>mapSize ) : 
         mapSize_(mapSize.first - 1, mapSize.second -1) {

initializeIslands(11, checkDuplicateCoordination(island_));
}

std::size_t Map::randomGenerate(std::size_t min, std::size_t max){
    	std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<size_t>dist(min, max);
		std::size_t random_pos = dist(mt);
        return random_pos;
}

void Map::initializeIslands(const std::size_t numberOfIslands, bool ifDuplicate){
    for (size_t i = 0; i < numberOfIslands; i++){
        if (ifDuplicate == true){
            i--;
        } else {
        island_.push_back(Island(randomGenerate(0, mapSize_.first), randomGenerate(0, mapSize_.second)));
        }
    }
}

bool Map::checkDuplicateCoordination(std::vector<Island>& island){
    auto duplicate_island = std::find_if(begin(island), end(island), [&](const auto& duplicate)
    {
        return island[island.size() - 1] == duplicate;
    });

    if (duplicate_island != island.end()){
        return true;
    } else {
        return false;
    }
}

Island* Map::getIsland(const Coordinates& coordinate){
    auto iterator_island = std::find_if(island_.begin(), island_.end(), [&](Island elements){return elements.getCoorditates() == coordinate; });
    return iterator_island != island_.end() ? &(*iterator_island) : nullptr;
}





