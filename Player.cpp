#include "Player.hpp"
#include "Alcohol.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "DryFruit.hpp"

#include <algorithm>
#include <cctype>

Player::Player(Time* time) : 
                ship_(std::make_shared<Ship>("Test_NAME", 30, 100, 50, time)){

}

void Player::checkAvailableSpace(){
    availableSpace_ = ship_.get()->getCapacity();
}

void Player::payCrew(int payCrew){
    if (money_ <= payCrew) {
        money_ = 0;
    } else {
        money_ -= payCrew;
    }
}

void Player::loadShip(std::shared_ptr<Cargo>cargo){
    ship_->load(cargo);
}

void Player::unloadShip(std::shared_ptr<Cargo>cargo){
    ship_->unload(cargo);
}

void Player::setPlayerPosition(std::pair<int, int> position){
    playerPosition_.first += position.first;
    playerPosition_.second += position.second;
}