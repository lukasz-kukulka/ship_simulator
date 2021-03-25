#include "Cargo.hpp"

Cargo::Cargo(std::string name, 
	  std::size_t amount, 
	  std::size_t bestPrice) : name_(name), amount_(amount), bestPrice_(bestPrice){
	
}

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