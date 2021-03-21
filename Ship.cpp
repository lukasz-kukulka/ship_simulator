#include "Ship.hpp"
#include <algorithm>
#include <iostream>

Ship::Ship(){}

Ship::Ship(int id, 
           const std::string& name, 
           std::size_t speed, 
           std::size_t maxCrew, 
           std::size_t capacity)
           : id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity) {}
Ship::Ship(int id, 
           std::size_t speed, 
           std::size_t maxCrew) : Ship(id, "", speed, maxCrew, 0) {}
         

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

// std::vector<Cargo> Ship::getCargo(){
//     std::vector<Cargo>cargo;
//     return cargo;
// }

// void Ship::load(std::shared_ptr<Cargo> cargo) {
//     cargo_.push_back(cargo);
// }

//void unload(Cargo* cargo){
    //auto result1 = std::find(std::begin(cargo_), std::end(cargo_), cargo);
//}