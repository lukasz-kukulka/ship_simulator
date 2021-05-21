#include "Ship.hpp"
#include <algorithm>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

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
    delegate_->payCrew(crew_);
}

std::ostream& operator<<(std::ostream& oper, const Ship& ship){
    oper << "|" << std::setfill('-') << std::setw (77) << "|\n";
    oper << "|" << std::setfill('-') << std::setw (77) << "|\n";
    oper << "|" << std::setfill(' ') << std::setw (6) << "|" << std::setw (20) << "|" << std::setw (20) << "|" << std::setw (31) << "|\n";
    oper << "|" << std::setw (4) << "ID" << std::setw (2) << "|";
    oper << std::setw (14) << "CARGO NAME" << std::setw (6) << "|";
    oper << std::setw (12) << "AMOUNT" << std::setw (8) << "|";
    oper << std::setw (23) << "UNIQUE STATISTIC" << std::setw (7) << "|";
    oper << "\n|" << std::setw (6) << "|" << std::setw (20) << "|" << std::setw (20) << "|" << std::setw (31) << "|\n";
    oper << "|" << std::setfill('-') << std::setw (77) << "|\n";
    int it = 1;
    for (const auto& cargo : ship.cargo_) {
        oper << std::setfill(' ') << "|" << std::setw (static_cast<int>((std::to_string(it)).size() / 2 + 3)) << it << std::setw (static_cast<int>(3 - ((std::to_string(it)).size() / 2))) << "|";
        oper << std::setw (static_cast<int>(cargo->getName().size() / 2 + 10)) << cargo->getName() << std::setw (static_cast<int>(10 - (cargo->getName().size() / 2))) << "|";
        oper << std::setw (static_cast<int>(std::to_string(cargo->getAmount()).size() / 2 + 10)) << cargo->getAmount() << std::setw (static_cast<int>(10 - (std::to_string(cargo->getAmount()).size() / 2))) << "|";
        oper << std::setw (static_cast<int>(cargo->getUniqueStat().size() / 2 + 15)) << cargo->getUniqueStat() << std::setw (static_cast<int>(16 - (cargo->getUniqueStat().size() / 2))) << "|\n";
        oper << "|" << std::setfill('-') << std::setw (77) << "|\n";
        it++;
    }
    return oper;
}