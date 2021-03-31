#include "Ship.hpp"
#include <algorithm>
#include <iostream>

Ship::Ship(int id, 
           const std::string& name, 
           std::size_t speed, 
           int maxCrew, 
           std::size_t capacity, Delegate* delegate) : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity), delegate_(delegate) {}
Ship::Ship(int id, 
           std::size_t speed, 
           int maxCrew, Delegate* delegate) : Ship(id, "", speed, maxCrew, 0, delegate) {}
         

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

void Ship::unload(Cargo* cargo){
    auto checkCargo = std::find_if(std::begin(cargo_), std::end(cargo_), [cargo](const auto& ele){return cargo == ele.get() ;});
    cargo_.erase(checkCargo);

}

void Ship::nextDay(){
    delegate_->payCrew(crew_);
}