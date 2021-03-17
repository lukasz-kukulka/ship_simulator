#include "Island.hpp"
#include <utility>

Island::Island(std::size_t positionX, 
               std::size_t positionY) : position_(Coordinates(positionX, positionY)) {}

bool Island::operator==(const Island& islandCoordinates) const{
    if (getCoorditates() == islandCoordinates.getCoorditates()) {
	    return true;
    } else {
        return false;
    }
}

Coordinates Island::getCoorditates() const {
    return position_;
}
