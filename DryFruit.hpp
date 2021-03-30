#pragma once
#include "Fruit.hpp"

class DryFruit : public Fruit{

public:
    DryFruit();

    std::size_t getPrice() const;
    std::size_t getRottenTime() { return rottenTime_; }
private:
    void countRottenTime();

};