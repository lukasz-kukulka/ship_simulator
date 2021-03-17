#include "Map.hpp"
#include <algorithm>
#include <random>
#include <iostream>

Map::Map(){

initializeIslands(10, checkDuplicateCoordination(island_));

}

std::size_t Map::randomGenerate(std::size_t min, std::size_t max){
    	std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int>dist(min, max);
		std::size_t random_pos = dist(mt);
        return random_pos;
}

void Map::initializeIslands(const std::size_t numberOfIslands, bool ifDuplicate){
    for (int i = 0; i < numberOfIslands; i++){
        if (ifDuplicate == true){
            i--;
        } else {
        island_.push_back(Island(randomGenerate(0, 100), randomGenerate(0, 100)));
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





