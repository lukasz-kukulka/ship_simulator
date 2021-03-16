#include "Island.hpp"
#include <utility>

Island::Island(std::size_t positionX, std::size_t positionY) : position_(positionX, positionY) {
}

bool Island::operator==(const Island& islandCoordinates) const{
    if (getCoorditates() == islandCoordinates.getCoorditates()) {
	    return true;
    } else {
        return false;
    }
}

std::pair<size_t, size_t> Island::getCoorditates() const {
    return std::make_pair (position_.getPositionX(), position_.getPositionY());
}
