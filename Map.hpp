#pragma once
#include <vector>
#include "Coordinates.hpp"
#include "Island.hpp"


class Map{

public:
    Map();
    std::size_t randomGenerate(std::size_t, std::size_t);
    //Island* getIsland(const Coordinates&);
    Island* getIsland(const Island::Coordinates&);

private:
    std::vector<Island>island_;
    Island* currentPosition_;
    void initializeIslands(const std::size_t, bool);
    bool checkDuplicateCoordination(std::vector<Island>&);
    
};