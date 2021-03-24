#include "Store.hpp"

Store::Store(size_t positionX, size_t positionY) : positionX_(positionX), positionY_(positionY){

}

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player){
    //if (checkMoney(player->getAvailableSpace()))

    return tradeStatus;
}
Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player){
    return tradeStatus;
}


bool Store::checkMoney(size_t playerMoney, size_t itemPrice, size_t itemsQuantity){
    if (playerMoney >= (itemPrice * itemsQuantity)){
        return true;
    } else {
        std::cerr << "You don't have enought money\n";
        return false;
    }
}
bool Store::checkCargo(size_t quantityInStock, size_t quantityToBuy){
    if (quantityInStock >= quantityToBuy){
        return true;
    } else {
        std::cerr << "This store don't have enough cargo\n";
        return false;
    }
}
bool Store::checkSpace(size_t quantityToBuy, size_t availablePlayerSpace){
    if (quantityToBuy <= availablePlayerSpace){
        return true;
    } else {
        std::cerr << "You dont have enough space in your ship\n";
        return false;
    }
}