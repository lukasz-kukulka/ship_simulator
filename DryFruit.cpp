#include "DryFruit.hpp"
#include <iostream>

DryFruit::DryFruit(std::string name, 
             size_t amount, 
             size_t bestPrice) : Fruit(name, amount, bestPrice) {

}


std::size_t DryFruit::getRottenTime() const { 
    return rottenTime_ * 10 - static_cast<size_t>(dryFruitRottenTime_); 
}

std::size_t DryFruit::getPrice() const {
    return Fruit::getPrice() * 10;
}

void DryFruit::countRottenTime(){
    if (dryFruitRottenTime_ <= 10){
        dryFruitRottenTime_++;
        
    } else {
        rottenTime_--;
        dryFruitRottenTime_ = 0;
    }
} 

std::string DryFruit::getUniqueStat() const {
    return std::to_string(getRottenTime()) + " days to rotten";
}

void DryFruit::nextDay(){
    countRottenTime();
}