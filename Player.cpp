#include "Player.hpp"

Player::Player() {

}

void Player::checkAvailableSpace(){
    availableSpace_ = ship_->getCapacity() - ship_->getCargo().getAmount();
}
