#pragma once
#include <iostream>
#include "Cargo.hpp"

class Fruit : public Cargo {

public:

    Fruit& operator--();

    std::size_t getPrice() const override;
    std::string getName() const override { return name_; }
    std::size_t getAmount() const override { return amount_; }
    std::size_t getBestPrice() const override{ return bestPrice_; }
    std::size_t getRottenTime() const { return rottenTime_; }

private:
    std::size_t rottenTime_ { 10 };

};