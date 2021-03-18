#pragma once
#include "Cargo.hpp"
#include "Ship.hpp"
#include <memory>

class Player{

public:

Player();

size_t getMoney() const { return money_; }
size_t getAvailableSpace() const { return availableSpace_; }
size_t getSpeed() const { return startPlayerShip_.getSpeed(); }
Cargo* getCargo(size_t index) const { return &startPlayerShip_.getCargo(); }

private:
Ship startPlayerShip_;
std::shared_ptr<Ship> ship_;
size_t money_;
size_t availableSpace_;

};

