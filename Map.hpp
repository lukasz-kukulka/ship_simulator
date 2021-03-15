#pragma once
#include <vector>
#include "Island.hpp"
#include <random>
#include <iostream>

class Map{

public:
    Map();
    std::size_t randomGenerate(std::size_t, std::size_t);

private:
    std::vector<Island>island;
    Island* currentPosition_;
    std::size_t randomPositionX, randomPositionY;
    
};