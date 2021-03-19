#pragma once
#include "Cargo.hpp"
#include "Ship.hpp"
#include <memory>

class Player{

public:

Player();

size_t getMoney() const { return money_; }
size_t getAvailableSpace() const { return availableSpace_; }
size_t getSpeed() const { return ship_->getSpeed(); }
Cargo* getCargo(size_t index) const { return &startPlayerShip_.getCargo(); }

private:

Ship startPlayerShip_ = { };
std::shared_ptr<Ship> ship_ = nullptr;
size_t money_ = { };
size_t availableSpace_ = { 1 };

void checkAvailableSpace();

//W klasie Player napisz prywatną funkcję, która obliczać będzie availableSpace_ na podstawie aktualnej ilości towaru na statku.
};

