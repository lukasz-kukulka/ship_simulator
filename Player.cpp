#include "Player.hpp"
#include "Alcohol.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "DryFruit.hpp"

#include <algorithm>

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

// Cargo* Player::getCargo(uint8_t index) const{
//     return ;
// }

void Player::addCargoToShip(std::shared_ptr<Cargo>cargo, int8_t value){
    uint8_t iterator = 0;
    auto result = std::find_if(cargo_.begin(), cargo_.end(), [&](auto element) { 
        iterator++;
        return element == cargo; 
        });
    if (result != cargo_.end()){
        cargo_[iterator]->addSubstractAmout(value);
    } else {
        //cargo_.push_back(cargo.get());
    }
}