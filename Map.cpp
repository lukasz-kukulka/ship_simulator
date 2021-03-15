#include "Map.hpp"


Map::Map(){
    //std::vector<Island&>island;

    for (int i = 0; i < 10; i++){
        island.push_back(Island(randomGenerate(0, 100), randomGenerate(0, 100)));
    }
}

std::size_t Map::randomGenerate(std::size_t min, std::size_t max){
    	std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int>dist(min, max);
		std::size_t random_pos = dist(mt);
        return random_pos;
}






