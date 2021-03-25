#include "Alcohol.hpp"

Cargo& Cargo::operator+=(const size_t addAmount){
    amount_ +=addAmount;
    return *this;
}
Cargo& Cargo::operator-=(const size_t delAmount){
    if (delAmount > amount_){
        return *this;
    } else {
        amount_ -= delAmount;
        return *this;
    }
}
bool Cargo::operator==(const Cargo& cargoCompare) const{
	if (name_ == cargoCompare.name_){
		return true;
	} else {
		return false;
	}
}

std::size_t Alcohol::getPrice() const {
    return price_ / maxPurity_ * purity_;
}