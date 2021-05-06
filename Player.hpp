#pragma once
#include "Cargo.hpp"
#include "Ship.hpp"
#include "Time.hpp"
#include "Coordinates.hpp"

#include <memory>
#include <vector>

class Player : public Ship::Delegate {

public:
Player(Time*);

size_t getMoney() const { return money_; }
size_t getAvailableSpace() const { return availableSpace_; }
size_t getSpeed() const { return ship_->getSpeed(); }
Coordinates getPlayerPosition() const { return position_; }
//std::pair<int, int> getPlayerPosition() const { return playerPosition_; }
void setPlayerPosition(int, int);
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
Coordinates position_;
//std::pair<int, int>playerPosition_ { 0, 0 };

};