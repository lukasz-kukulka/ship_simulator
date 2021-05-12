#include "Player.hpp"
#include "Alcohol.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "DryFruit.hpp"

#include <algorithm>
#include <cctype>

Player::Player(Time* time) : 
                ship_(std::make_shared<Ship>("Test_NAME", 30, 100, 50, time, this)){

}

void Player::checkAvailableSpace(){
    availableSpace_ = ship_.get()->getCapacity();
}

void Player::payCrew(int payCrew){
    std::cout <<"Pay crew i Player\n"; 
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

void Player::setPlayerPosition(int posX, int posY){
    position_.setCoordinates(posX, posY);
}