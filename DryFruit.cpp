#include "DryFruit.hpp"


std::size_t DryFruit::getPrice() const{
    return Fruit::getPrice() * 3;
}

void DryFruit::countRottenTime(){
    static uint8_t dryFruitRottenTime = 0;
    if (dryFruitRottenTime <= 10){
        dryFruitRottenTime++;
    } else {
        rottenTime_--;
    }
} 