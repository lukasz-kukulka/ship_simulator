#pragma once
#include "Coordinates.hpp"

class Island{

public:
    Island() = default; 
    Island(std::size_t, std::size_t);

    bool operator==(const Island&) const;

    Coordinates getCoorditates() const;

private:
    Coordinates position_;

};