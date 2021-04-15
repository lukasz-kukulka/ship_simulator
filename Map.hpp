#pragma once
#include "Coordinates.hpp"
#include "Island.hpp"

#include <utility>
#include <vector>

class Map{

public:
    Map(std::pair<uint8_t, uint8_t>);
    std::size_t randomGenerate(std::size_t, std::size_t);
    Island* getIsland(const Coordinates&);
    
private:
    std::vector<Island>island_;
    Island* currentPosition_;
    void initializeIslands(const std::size_t, bool);
    bool checkDuplicateCoordination(std::vector<Island>&);
    std::pair<uint8_t, uint8_t>mapSize_;
};