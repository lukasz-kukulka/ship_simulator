#include "Store.hpp"

Store::Store(size_t positionX, size_t positionY) : positionX_(positionX), positionY_(positionY){

}

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player){
    generateItemStatus(cargo, amount, player);
    return tradeStatus_;
}

Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player){
    generateItemStatus(cargo, amount, player);
    return tradeStatus_;
}

void Store::generateItemStatus(Cargo* cargo, size_t amount, Player* player){
    tradeStatus_ = Response::done;
    checkMoney(player->getMoney(), cargo->getPrice(), amount);
    checkCargo(getQuantity(), amount);
    checkSpace(amount, player->getAvailableSpace());
    
}

void Store::printMessage(){
    std::cout << messageError_;
}

bool Store::checkMoney(size_t playerMoney, size_t itemPrice, size_t itemsQuantity){
    if (playerMoney >= (itemPrice * itemsQuantity)){
        return true;
    } else {
        messageError_ = "You don't have enought money\n";
        tradeStatus_ = Response::lack_of_money;
        return false;
    }
}
bool Store::checkCargo(size_t quantityInStock, size_t quantityToBuy){
    if (quantityInStock >= quantityToBuy){
        return true;
    } else {
        messageError_ = "This store don't have enough cargo\n";
        tradeStatus_ = Response::lack_of_cargo;
        return false;
    }
}
bool Store::checkSpace(size_t quantityToBuy, size_t availablePlayerSpace){
    if (quantityToBuy <= availablePlayerSpace){
        return true;
    } else {
        messageError_ = "You dont have enough space in your ship\n";
        tradeStatus_ = Response::lack_of_space;
        return false;
    }
}