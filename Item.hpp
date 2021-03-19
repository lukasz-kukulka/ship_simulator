#pragma once
#include <iostream>
#include "Cargo.hpp"

class Item : public Cargo {

public:

    std::size_t getPrice() const override;
    std::string getName() const override { return name_; }
    std::size_t getAmount() const override { return amount_; }
    std::size_t getBestPrice() const override{ return bestPrice_; }

private:
enum rarity_ { common, rare, epic, legendary } itemRarity;

};