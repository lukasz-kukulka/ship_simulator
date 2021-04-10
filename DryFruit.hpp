#pragma once
#include "Fruit.hpp"

class DryFruit : public Fruit{

public:
    DryFruit(std::string, size_t, size_t);

    std::size_t getPrice();
    std::size_t getRottenTime() const;
    std::string getUniqueStat() const;
    static uint16_t dryFruitRottenTime_;
private:
    void countRottenTime();
    
};