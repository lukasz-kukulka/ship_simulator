#include "Fruit.hpp"

Fruit::Fruit(std::string name, 
             size_t amount, 
             size_t bestPrice) : Cargo(name, amount, bestPrice){
}

Fruit& Fruit::operator--(){
    if(Fruit::rottenTime_ > 0){
        --rottenTime_;
    } else {
        std::cerr << "This fruit is completly rotten alredy 0\n";
    }
    return *this;
}

Cargo& Fruit::operator+=(const size_t addAmount){
    amount_ +=addAmount;
    return *this;
}
Cargo& Fruit::operator-=(const size_t delAmount){
    if (delAmount > amount_){
        return *this;
    } else {
        amount_ -= delAmount;
        return *this;
    }
}
bool Fruit::operator==(const Cargo& cargoCompare) const{
	if (name_ == cargoCompare.getName()){
		return true;
	} else {
		return false;
	}
}

std::size_t Fruit::getPrice() const { 
    return price_ * (rottenTime_/10);
}

void Fruit::nextDay(){
    rottenTime_--;
}

std::string Fruit::getUniqueStat() const {
    return std::to_string(rottenTime_) + " days to rotten";
}

void Fruit::changeAmount(int8_t valueOne, int8_t valueTwo) {
    if (static_cast<int8_t>(amount_) + (valueOne - valueTwo) <= 0) {
        amount_ = 0;
    } else {
        amount_ += (valueOne - valueTwo);
    }
}

void Fruit::addSubstractAmout(int8_t value) {
    amount_ += (value);
}