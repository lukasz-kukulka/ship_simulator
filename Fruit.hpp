#pragma once
#include <iostream>
#include "Cargo.hpp"

class Fruit : public Cargo {

public:

    Fruit& operator--();
    // //override after Cargo class
    // Cargo& operator+=(const size_t) override;
    // Cargo& operator-=(const size_t) override;
    // bool operator==(const Cargo&) const override;
    std::size_t getPrice() const override;
    std::string getName() const override { return name_; }
    std::size_t getAmount() const override { return amount_; }
    std::size_t getBestPrice() const override{ return bestPrice_; }
    std::size_t getRottenTime() const { return rottenTime_; }

private:
    std::size_t rottenTime_ { 10 };

};