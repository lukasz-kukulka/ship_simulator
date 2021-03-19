#pragma once
#include <iostream>
#include "Cargo.hpp"

class Item : public Cargo {

public:
    enum class Rarity { common = 1, 
                        rare = 2, 
                        epic = 4,
                        legendary = 8 };

    std::size_t getPrice() const override;
    std::string getName() const override { return name_; }
    std::size_t getAmount() const override { return amount_; }
    std::size_t getBestPrice() const override{ return bestPrice_; }

private:
    Rarity rarity_

};