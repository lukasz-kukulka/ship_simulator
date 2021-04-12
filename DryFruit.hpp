#pragma once
#include "Fruit.hpp"

class DryFruit : public Fruit
{
public:
    DryFruit(std::string, size_t, size_t);
    //~DryFruit() override;

    std::size_t getPrice() const override;
    std::size_t getRottenTime() const;
    std::string getUniqueStat() const override;
    void nextDay() override;
private:
    void countRottenTime();
    uint16_t dryFruitRottenTime_ { 0 };

};