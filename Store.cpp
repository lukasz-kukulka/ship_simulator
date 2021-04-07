#include "Store.hpp"
#include <random>
#include <iostream>
#include "Alcohol.hpp"
#include <iomanip>

Store::Store(Time* time) : time_(time) {
    time_->addObserwer(this);
}

Store::~Store(){
    time_->deleteObserwer(this);
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

size_t Store::randomGenerate(int min, int max){
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

void Store::nextDay(){
    
}

void Store::generateStockInStore(){
    size_t itemsNumber = randomGenerate(1, 10);
    itemsNumber++; // change this
    
}

// std::ostream& operator<<(std::ostream& oper, const Store& store){
//     oper << "|" << std::setfill('-')  << std::setw (50) << "|\n";
//     for (const auto& cargo : store.cargo_) {
        
//         oper << "|" << std::setfill(' ')  << std::setw (50) << cargo->getName();
//         std::cout << "|" << std::setfill('-')  << std::setw (50) << "|\n";
        
//     }
    
//     return oper;
// }

void Store::generateItems(){
    //std::make_shared<Alcohol>
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("TEST_NAME", 200, 100, 20)));
}