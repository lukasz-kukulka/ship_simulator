#pragma once
#include <string>
#include <iostream>

class Cargo{

public:
    Cargo();

    Cargo& operator+=(const int addAmount);
    Cargo& operator-=(const int delAmount);

private:
    std::string name_;
    std::size_t amount_;
    std::size_t bestPrice_;
};