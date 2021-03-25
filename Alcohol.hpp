#pragma once
#include <iostream>
#include "Cargo.hpp"

class Alcohol : public Cargo {

public:
    //override after Cargo class
    Cargo& operator+=(const size_t) override;
    Cargo& operator-=(const size_t) override;
    bool operator==(const Cargo&) const override;
    std::size_t getPrice() const override;
    std::string getName() const override { return name_; }
    std::size_t getAmount() const override { return amount_; }
    std::size_t getBestPrice() const override{ return bestPrice_; }
    std::size_t getPurity() const { return purity_; }

private:
    std::size_t purity_ { 40 };
    std::size_t const maxPurity_ = { 96 };

};