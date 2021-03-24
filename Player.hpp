#pragma once
#include "Cargo.hpp"
#include "Ship.hpp"
#include <memory>

class Player{

public:

Player() = default;

size_t getMoney() const { return money_; }
size_t getAvailableSpace() const { return availableSpace_; }
size_t getSpeed() const { return ship_->getSpeed(); }
Cargo* getCargo(size_t index) const; 

private:

std::shared_ptr<Ship> ship_;
size_t money_;
size_t availableSpace_ { 100 };

void checkAvailableSpace();

//W klasie Player napisz prywatną funkcję, która obliczać będzie availableSpace_ na podstawie aktualnej ilości towaru na statku.
};

