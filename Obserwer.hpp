#pragma once
#include <iostream>

class Obserwer 
{
public: 
    virtual void nextDay() = 0;
    virtual ~Obserwer() = default;
};