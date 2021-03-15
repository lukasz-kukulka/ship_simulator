#pragma once
#include "Coordinates.hpp"

class Island{

public:

    Island(std::size_t, std::size_t);
    std::pair<size_t, size_t> getCoorditates();

private:
    Coordinates position_;

};