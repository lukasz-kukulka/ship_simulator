#include "Time.hpp"
#include <algorithm>

void Time::addObserwer(Obserwer* obserwer){
    obserwer_.push_back(obserwer);
}

void Time::deleteObserwer(Obserwer* obserwer){
    obserwer_.erase(std::find(begin(obserwer_), end(obserwer_), obserwer));
}