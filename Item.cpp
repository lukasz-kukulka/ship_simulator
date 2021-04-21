#include "Item.hpp"
#include <string>

Item::Item(std::string name, std::size_t amount, std::size_t bestPrice, size_t rarity) : Cargo(name, amount, bestPrice)
{
    rarity_ = static_cast<Rarity>(countRarity(static_cast<uint8_t>(rarity)));
}

uint8_t Item::countRarity(uint8_t rarity){
    uint8_t temp = 16;
    for(uint8_t i = 0; i < rarity; i++){
        temp = temp / 2;
    }
    return temp;
}

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
    if (static_cast<int>(rarity_) == 1){
        return "RARITY: COMMON";
    } else if (static_cast<int>(rarity_) == 2){
        return "RARITY: RARE";
    } else if (static_cast<int>(rarity_) == 4){
        return "RARITY: EPIC";
    } else if (static_cast<int>(rarity_) == 8){
        return "RARITY: LEGENDARY";
    } else {
        return "---------------";
    }
}

void Item::changeAmount(int8_t valueOne, int8_t valueTwo) {
    if (static_cast<int8_t>(amount_) + (valueOne - valueTwo) <= 0){
        amount_ = 0;
    } else {
        amount_ += ((valueOne - valueTwo)/ (static_cast<int8_t>(rarity_) * 2));
    }
}

std::size_t Item::getPrice() const{
    return price_ * static_cast<size_t>(rarity_);
}

void Item::addSubstractAmout(int8_t value) {
    amount_ += (value);
}