#include "Item.hpp"

//Item::Item(std::string name, std::size_t amount, std::size_t bestPrice) {}//: Cargo(name, amount, bestPrice) {}

// std::size_t Item::getPrice() const{
//     return static_cast<int>(rarity_) * price_;
// }

Cargo& Item::operator+=(const size_t addAmount){
    amount_ +=addAmount;
    return *this;
}
Cargo& Item::operator-=(const size_t delAmount){
    if (delAmount > amount_){
        return *this;
    } else {
        amount_ -= delAmount;
        return *this;
    }
}
bool Item::operator==(const Cargo& cargoCompare) const{
	if (name_ == cargoCompare.getName()){
		return true;
	} else {
		return false;
	}
}

std::string Item::getUniqueStat() const{
    
    return "RARITY";
}

void Item::changeAmount(int8_t valueOne, int8_t valueTwo) {
    amount_ += (valueOne - valueTwo);
}