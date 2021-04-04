#pragma once
#include "Obserwer.hpp"
#include <vector>


class Time
{
public:
    Time();
    void addObserwer(Obserwer*);
    void deleteObserwer(Obserwer*);
    int getElapseTime() const { return elapseTime_; }

private:
    int elapseTime_;
    std::vector<Obserwer*>obserwer_;


};