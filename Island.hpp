#pragma once
#include "Coordinates.hpp"

class Island{

public:

    Island(std::size_t, std::size_t);

    bool operator==(const Island&) const;

    std::pair<size_t, size_t> getCoorditates() const;
    

private:
    Coordinates position_;

};