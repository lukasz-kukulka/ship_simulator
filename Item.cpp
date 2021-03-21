#include "Item.hpp"


std::size_t Item::getPrice() const{
    return static_cast<int>(rarity_) * price_;
}