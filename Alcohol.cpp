#include "Alcohol.hpp"

Cargo& Alcohol::operator+=(const size_t addAmount){
    amount_ +=addAmount;
    return *this;
}
Cargo& Alcohol::operator-=(const size_t delAmount){
    if (delAmount > amount_){
        return *this;
    } else {
        amount_ -= delAmount;
        return *this;
    }
}
bool Alcohol::operator==(const Cargo& cargoCompare) const{
	if (name_ == cargoCompare.getName()){
		return true;
	} else {
		return false;
	}
}

std::size_t Alcohol::getPrice() const {
    return price_ / maxPurity_ * purity_;
}