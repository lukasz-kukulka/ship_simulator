#pragma once
#include <string>
#include <iostream>

class Cargo{

public:
    Cargo();
    Cargo(std::string, std::size_t, std::size_t);

    Cargo& operator+=(const int addAmount);
    Cargo& operator-=(const int delAmount);
    bool operator==(const Cargo&) const;

    std::string getName() { return name_; }
    std::size_t getAmount() { return amount_; }
    std::size_t getBestPrice() { return bestPrice_; }

private:
    std::string name_;
    std::size_t amount_;
    std::size_t bestPrice_;
};