#pragma once
#include "Cargo.hpp"
#include "Ship.hpp"
#include <memory>

class Player : public Ship::Delegate {

public:

size_t getMoney() const { return money_; }
size_t getAvailableSpace() const { return availableSpace_; }
size_t getSpeed() const { return ship_->getSpeed(); }
Cargo* getCargo(size_t index) const; 
//overide from Delegate
void payCrew(int payCrew) override;

private:

std::shared_ptr<Ship> ship_;
int money_;
size_t availableSpace_ { 100 };

void checkAvailableSpace();

};

