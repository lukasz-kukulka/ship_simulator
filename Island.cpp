#include "Island.hpp"
#include <utility>

Island::Island() : position_(0, 0) {
}

std::pair<size_t, size_t> Island::getCoorditates(){
    return std::make_pair (position_.getPositionX(), position_.getPositionY());
}