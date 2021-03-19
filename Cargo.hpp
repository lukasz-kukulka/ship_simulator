#pragma once
#include <string>
#include <iostream>

class Cargo {

public:
    Cargo();
    Cargo(std::string, std::size_t, std::size_t);

    Cargo& operator+=(const int);
    Cargo& operator-=(const int);
    bool operator==(const Cargo&) const;

    virtual std::size_t getPrice() const = 0;
    virtual std::string getName() const = 0; // { return name_; }
    virtual std::size_t getAmount() const = 0; //{ return amount_; }
    virtual std::size_t getBestPrice() const = 0; //{ return bestPrice_; }

protected:
    std::size_t price_;
    std::string name_;
    std::size_t amount_;
    std::size_t bestPrice_;
};