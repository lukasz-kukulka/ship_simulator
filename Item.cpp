#include "Item.hpp"


std::size_t Item::getPrice() const{
    return static_cast<size_t>(rarity_) * price_;
}