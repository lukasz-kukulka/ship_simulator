#pragma once
#include "Obserwer.hpp"
#include <vector>


class Time
{
public:
    void addObserwer(Obserwer*);
    void deleteObserwer(Obserwer*);
    int getElapseTime() const { return elapseTime_; }
    void howManyObserwers();
    Time& operator++();
 

private:
    int elapseTime_ { 1 };
    std::vector<Obserwer*>obserwer_;
    void callingNextDay();


};