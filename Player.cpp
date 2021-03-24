#include "Player.hpp"




void Player::checkAvailableSpace(){
    //size_t test = Player::getCargo().getAmount();
    availableSpace_ = ship_.get()->getCapacity();
}
