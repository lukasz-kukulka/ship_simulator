#include "Time.hpp"
#include <algorithm>
#include <iostream>

void Time::addObserwer(Obserwer* obserwer){
    obserwer_.push_back(obserwer);
    //std::cout<<"CREATE OBSERWER  " << obserwer_.size() <<  "  <--- SIZE\n"; 
}

void Time::deleteObserwer(Obserwer* obserwer){
    obserwer_.erase(std::remove(obserwer_.begin(), obserwer_.end(), obserwer), obserwer_.end());
    //std::cout <<"DELETE OBSERWER     " << obserwer_.size() <<  "  <--- SIZE\n"; 
}

Time& Time::operator++() {
    //callingNextDay();
    for (auto observer : obserwer_){
        observer->nextDay();
    }
        

    elapseTime_++;
    return *this;
}

void Time::howManyObserwers(){
    std::cout <<"OBSERWERS     " << obserwer_.size() <<  "  <--- SIZE\n"; 
}

void Time::callingNextDay(){
    std::for_each(obserwer_.begin(), obserwer_.end(), [](const auto& ele){ ele->nextDay() ; std::cout  <<  "  <--- LAMPDA\n"; });
}