#pragma once
#include <string>
#include <iostream>
#include "Obserwer.hpp"

class Cargo : public Obserwer 
{
public:

    Cargo(std::string, std::size_t, std::size_t);
    virtual Cargo& operator+=(const size_t) = 0;
    virtual Cargo& operator-=(const size_t) = 0;
    virtual bool operator==(const Cargo&) const = 0;

    virtual std::size_t getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual std::size_t getAmount() const = 0;
    virtual std::size_t getBestPrice() const = 0;
    virtual std::string getUniqueStat() const = 0; 
    virtual void changeAmount(int8_t, int8_t) = 0;

protected:
    
    std::size_t price_ = { 10 }; 
    std::string name_ = {"None"};
    std::size_t amount_ = { 0 };
    std::size_t bestPrice_ = { 0 };
};