#include "Island.hpp"
#include <utility>

Island::Island(std::size_t positionX, std::size_t positionY) : position_(positionX, positionY) {
}

std::pair<size_t, size_t> Island::getCoorditates(){
    return std::make_pair (position_.getPositionX(), position_.getPositionY());
}
