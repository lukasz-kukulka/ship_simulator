#include "Player.hpp"

void Player::checkAvailableSpace(){
    //size_t test = Player::getCargo().getAmount();
    availableSpace_ = ship_.get()->getCapacity();
}

void Player::payCrew(int payCrew){
    if (money_ <= payCrew) {
        money_ = 0;
    } else {
        money_ -= payCrew;
    }
}