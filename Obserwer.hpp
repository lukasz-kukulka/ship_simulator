#pragma once

class Obserwer 
{
public: 
    virtual void nextDay() = 0;
    virtual ~Obserwer(){}; 
};