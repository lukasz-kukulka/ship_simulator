#pragma once
#include "Cargo.hpp"
#include "Ship.hpp"
#include "Time.hpp"

#include <memory>
#include <vector>

class Player : public Ship::Delegate {

public:
Player(Time*);

size_t getMoney() const { return money_; }
size_t getAvailableSpace() const { return availableSpace_; }
size_t getSpeed() const { return ship_->getSpeed(); }
std::pair<int, int> getPlayerPosition() const { return playerPosition_; }
void setPlayerPosition(std::pair<int, int>);
void loadShip(std::shared_ptr<Cargo>);
void unloadShip(std::shared_ptr<Cargo>);
void addCargoToShip(std::shared_ptr<Cargo>, int8_t);
//overide from Delegate
void payCrew(int payCrew) override;

private:
std::shared_ptr<Ship> ship_;
int money_;
size_t availableSpace_ { 100 };
void checkAvailableSpace();
std::pair<int, int>playerPosition_ { 0, 0 };

};