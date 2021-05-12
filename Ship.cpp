#include "Ship.hpp"
#include <algorithm>
#include <iostream>

Ship::Ship(const std::string& name, 
           std::size_t speed, 
           int maxCrew, 
           std::size_t capacity,  
           Time* time,
           Delegate* delegate) : name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity), time_(time), delegate_(delegate){
               time_->addObserwer(this);
           }
Ship::Ship(std::size_t speed, 
           int maxCrew,  
           Time* time, Delegate* delegate) : Ship("Empty", speed, maxCrew, 0, time, delegate) {}

Ship::~Ship(){
    time_->deleteObserwer(this);
}         

Ship& Ship::operator+=(const int addCrew){
    if (crew_ + addCrew <= maxCrew_){
        crew_ += addCrew;
        return *this;
    }
	else{
		std::cerr << "Maximum crew value is " << maxCrew_ << "\n";
		return *this;
	}
}

Ship& Ship::operator-=(const int delCrew){
    if (crew_ >= delCrew){
        crew_ -= delCrew;
        return *this;
    }
	else{
		std::cerr << "Value can't be less then 0 " << maxCrew_ << "\n";
		return *this;
	}
}


void Ship::load(const std::shared_ptr<Cargo> cargo) {
    auto checkCargo = std::find_if(std::begin(cargo_), std::end(cargo_), [cargo](const auto& ele){return cargo == ele ;});
    if(checkCargo != cargo_.end()){
        auto ptrToElement = checkCargo->get();
        ptrToElement += cargo->getAmount();
    } else {
        cargo_.push_back(cargo); 
    }
    
}

void Ship::unload(const std::shared_ptr<Cargo> cargo){
    auto checkCargo = std::find_if(std::begin(cargo_), std::end(cargo_), [cargo](const auto& ele){return cargo == ele ;});
    cargo_.erase(checkCargo);

}

void Ship::nextDay(){
    //std::cout <<"Check nextDay in Ship\n"; 
    delegate_->payCrew(crew_);
}