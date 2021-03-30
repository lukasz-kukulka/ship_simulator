#include "Player.hpp"


void Player::nextDay(){
    money_ = money_ - ship_->getCrew();
}

void Player::checkAvailableSpace(){
    //size_t test = Player::getCargo().getAmount();
    availableSpace_ = ship_.get()->getCapacity();
}
