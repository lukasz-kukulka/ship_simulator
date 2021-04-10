#pragma once
#include <iostream>
#include "Cargo.hpp"
#include <string>

class Fruit : public Cargo {

public:
    Fruit (std::string, size_t, size_t);
    ~Fruit() override {};
    Fruit& operator--();

    //override from Cargo class
    Cargo& operator+=(const size_t) override;
    Cargo& operator-=(const size_t) override;
    bool operator==(const Cargo&) const override;
    std::size_t getPrice() const override;
    std::string getName() const override { return name_; }
    std::size_t getAmount() const override { return amount_; }
    std::size_t getBestPrice() const override{ return bestPrice_; }
    std::size_t getRottenTime() const { return rottenTime_; }
    void nextDay() override;
    std::string getUniqueStat() const override;

    void changeAmount(int8_t, int8_t) override;
protected:
    std::size_t rottenTime_ { 10 };


};