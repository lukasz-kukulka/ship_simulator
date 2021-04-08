#pragma once
#include <iostream>
#include "Cargo.hpp"
#include <string>

class Item : public Cargo {

public:
    //Item(std::string, std::size_t, std::size_t);

    enum class Rarity { common = 1, 
                        rare = 2, 
                        epic = 4,
                        legendary = 8 };
    //override from Cargo class
    Cargo& operator+=(const size_t) override;
    Cargo& operator-=(const size_t) override;
    bool operator==(const Cargo&) const override;
    //std::size_t getPrice() const override;
    std::string getName() const override { return name_; }
    std::size_t getAmount() const override { return amount_; }
    std::size_t getBestPrice() const override{ return bestPrice_; }
    std::string getUniqueStat() const override;
    //override Cargo
    //void nextDay() override;

    void changeAmount(int8_t, int8_t) override ;

private:
    Rarity rarity_ ;

};