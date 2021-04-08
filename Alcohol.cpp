#include "Alcohol.hpp"

Alcohol::Alcohol(std::string name, 
                 size_t amount, 
                 size_t bestPrice, 
                 uint purity) : Cargo(name, amount, bestPrice), purity_(purity) {

}

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

std::string Alcohol::getUniqueStat() const {
    return std::to_string(purity_) + " % of pure alcohol";
}

void Alcohol::changeAmount(int8_t valueOne, int8_t valueTwo) {
    if (static_cast<int8_t>(amount_) + (valueOne - valueTwo) <= 0){
        amount_ = 0;
    } else {
        amount_ += (valueOne - valueTwo);
    }
}