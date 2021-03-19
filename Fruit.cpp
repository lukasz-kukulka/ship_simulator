#include "Fruit.hpp"

Fruit& Fruit::operator--(){
    if(Fruit::rottenTime_ > 0){
        --rottenTime_;
    } else {
        std::cerr << "This fruit is completly rotten alredy 0\n";
    }
    return *this;
}

std::size_t Fruit::getPrice() const { 
    return price_ * (rottenTime_/10);
}