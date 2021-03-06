#include "Store.hpp"
#include "Alcohol.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "DryFruit.hpp"

#include <random>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>

Store::Store(Time* time) : time_(time) {
    time_->addObserwer(this);
    generateAllCargo();
}

Store::~Store(){
    this->time_->deleteObserwer(this);
}

Cargo* Store::getCargo(uint16_t pos){
    return cargo_[pos].get();
}

bool Store::checkCargoCondition(int index){
    if (index > getNoOffCargo() || index < 1) {
        system( "clear" );
        std::cout << "Wrong value, please insert correct value. Betwen 1 and " << getNoOffCargo() << " \n";
        return false;
    } else {
        return true;
    } 
}

bool Store::checkCargoRange(uint16_t index){
    if (index <= getNoOffCargo()){
        return true;
    } else {
        system( "clear" );
        std::cout << "Wrong value, please insert correct value. Betwen 1 and " << cargo_[numberCargoToCheck]->getAmount() << " \n";
        return false;
    }
}

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player){
    tradeStatus_ = Response::done;
    buyGenerateItemStatus(cargo, amount, player);
    std::cout << messageError_;
    if (tradeStatus_ == Response::done){
        cargo+= amount;
    }
    return tradeStatus_;
}

Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player){
///////////////////////only for tests////////////////////////////////////
    cargo->getPrice();
    cargo->getAmount();
    player->getAvailableSpace();
/////////////////////////////////////////////////////////////////////////
    cargo+= amount;
    //add add to player
    return Response::done;
}

void Store::buyGenerateItemStatus(Cargo* cargo, size_t amount, Player* player){
    tradeStatus_ = Response::done;
    checkMoney(player->getMoney(), cargo->getPrice(), amount);
    checkCargo(cargo->getAmount(), amount);
    checkSpace(amount, player->getAvailableSpace());
}


bool Store::ifCargoExist(Cargo* cargo){
    auto result = std::find_if(begin(cargo_), end(cargo_), [&] (auto element) { return element.get() == cargo; });
    if (result == cargo_.end()){
        return false;
    } else {
        return true;
    }
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
    for (int i = 0; i < cargoSize; i++){
        cargo_[i]->nextDay();
    }
    for (auto& cargo : cargo_) {
        cargo->changeAmount(static_cast<int8_t>(randomGenerate(0, 50)), static_cast<int8_t>(randomGenerate(0, 50)));
    }

}

std::ostream& operator<<(std::ostream& oper, const Store& store){
    oper << "|" << std::setfill('-') << std::setw (97) << "|\n";
    oper << "|" << std::setfill(' ') << std::setw (6) << "|" << std::setw (20) << "|" << std::setw (20) << "|" << std::setw (20) << "|" << std::setw (31) << "|\n";
    oper << "|" << std::setw (4) << "ID" << std::setw (2) << "|";
    oper << std::setw (14) << "CARGO NAME" << std::setw (6) << "|";
    oper << std::setw (12) << "AMOUNT" << std::setw (8) << "|";
    oper << std::setw (12) << "PRICE" << std::setw (8) << "|";
    oper << std::setw (23) << "UNIQUE STATISTIC" << std::setw (7) << "|";
    oper << "\n|" << std::setw (6) << "|" << std::setw (20) << "|" << std::setw (20) << "|" << std::setw (20) << "|" << std::setw (31) << "|\n";
    oper << "|" << std::setfill('-') << std::setw (97) << "|\n";
    int it = 1;
    for (const auto& cargo : store.cargo_) {
        oper << std::setfill(' ') << "|" << std::setw (static_cast<int>((std::to_string(it)).size() / 2 + 3)) << it << std::setw (static_cast<int>(3 - ((std::to_string(it)).size() / 2))) << "|";
        oper << std::setw (static_cast<int>(cargo->getName().size() / 2 + 10)) << cargo->getName() << std::setw (static_cast<int>(10 - (cargo->getName().size() / 2))) << "|";
        oper << std::setw (static_cast<int>(std::to_string(cargo->getAmount()).size() / 2 + 10)) << cargo->getAmount() << std::setw (static_cast<int>(10 - (std::to_string(cargo->getAmount()).size() / 2))) << "|";
        oper << std::setw (static_cast<int>(std::to_string(cargo->getBestPrice()).size() / 2 + 10)) << cargo->getBestPrice() << std::setw (static_cast<int>(10 - (std::to_string(cargo->getBestPrice()).size() / 2))) << "|";
        oper << std::setw (static_cast<int>(cargo->getUniqueStat().size() / 2 + 15)) << cargo->getUniqueStat() << std::setw (static_cast<int>(16 - (cargo->getUniqueStat().size() / 2))) << "|\n";
        oper << "|" << std::setfill('-') << std::setw (97) << "|\n";
        it++;
    }
    return oper;
}

void Store::generateAllCargo(){
    generateAlcohol();
    generateItems();
    cargoSize = static_cast<int>(cargo_.size());
    generateFruits();
    generateDryFruits();
}

void Store::generateAlcohol(){
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("Light beer", randomGenerate(0, 100), randomGenerate(10, 120), 3)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("Beer", randomGenerate(0, 100), randomGenerate(10, 140), 5)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("Dark beer", randomGenerate(0, 100), randomGenerate(15, 160), 7)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("White wine", randomGenerate(0, 100), randomGenerate(20, 180), 11)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("Red wine", randomGenerate(0, 100), randomGenerate(25, 200), 12)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("Martini", randomGenerate(0, 100), randomGenerate(30, 300), 15)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("Rum", randomGenerate(0, 100), randomGenerate(35, 400), 35)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("Whisky", randomGenerate(0, 100), randomGenerate(40, 500), 39)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("Wodka", randomGenerate(0, 100), randomGenerate(45, 600), 42)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("Gin", randomGenerate(0, 100), randomGenerate(50, 700), 37)));
    cargo_.push_back(std::make_shared<Alcohol>(Alcohol("Whisky", randomGenerate(0, 100), randomGenerate(100, 1000), 39)));
}

void Store::generateItems(){
    cargo_.push_back(std::make_shared<Item>(Item("Knife", randomGenerate(0, 2), randomGenerate(1000, 2000), randomGenerate(1, 4))));
    cargo_.push_back(std::make_shared<Item>(Item("Axe", randomGenerate(0, 2), randomGenerate(1000, 2000), randomGenerate(1, 4))));
    cargo_.push_back(std::make_shared<Item>(Item("Lamp", randomGenerate(0, 2), randomGenerate(1000, 2000), randomGenerate(1, 4))));
    cargo_.push_back(std::make_shared<Item>(Item("Helmet", randomGenerate(0, 2), randomGenerate(1000, 2000), randomGenerate(1, 4))));
    cargo_.push_back(std::make_shared<Item>(Item("Gloves", randomGenerate(0, 2), randomGenerate(1000, 2000), randomGenerate(1, 4))));
    cargo_.push_back(std::make_shared<Item>(Item("Shoes", randomGenerate(0, 2), randomGenerate(1000, 2000), randomGenerate(1, 4))));
    cargo_.push_back(std::make_shared<Item>(Item("Pot", randomGenerate(0, 2), randomGenerate(1000, 2000), randomGenerate(1, 4))));
    cargo_.push_back(std::make_shared<Item>(Item("Pan", randomGenerate(0, 2), randomGenerate(1000, 2000), randomGenerate(1, 4))));
    cargo_.push_back(std::make_shared<Item>(Item("Plate", randomGenerate(0, 2), randomGenerate(1000, 2000), randomGenerate(1, 4))));
    cargo_.push_back(std::make_shared<Item>(Item("Brush", randomGenerate(0, 2), randomGenerate(1000, 2000), randomGenerate(1, 4))));
}

void Store::generateFruits(){
    cargo_.push_back(std::make_shared<Fruit>(Fruit("Orange", randomGenerate(0, 100), randomGenerate(10, 20))));
    cargo_.push_back(std::make_shared<Fruit>(Fruit("Banana", randomGenerate(0, 100), randomGenerate(10, 20))));
    cargo_.push_back(std::make_shared<Fruit>(Fruit("Apple", randomGenerate(0, 100), randomGenerate(10, 20))));
    cargo_.push_back(std::make_shared<Fruit>(Fruit("Mango", randomGenerate(0, 100), randomGenerate(10, 20))));
    cargo_.push_back(std::make_shared<Fruit>(Fruit("Lemon", randomGenerate(0, 100), randomGenerate(10, 20))));
    cargo_.push_back(std::make_shared<Fruit>(Fruit("Grapes", randomGenerate(0, 100), randomGenerate(10, 20))));
    cargo_.push_back(std::make_shared<Fruit>(Fruit("Strawbery", randomGenerate(0, 100), randomGenerate(10, 20))));
    
}

void Store::generateDryFruits(){
    cargo_.push_back(std::make_shared<DryFruit>(DryFruit("Dry banana", randomGenerate(0, 30), randomGenerate(10, 20))));
    cargo_.push_back(std::make_shared<DryFruit>(DryFruit("Raisins", randomGenerate(0, 30), randomGenerate(10, 20))));
    cargo_.push_back(std::make_shared<DryFruit>(DryFruit("Dry apple", randomGenerate(0, 30), randomGenerate(10, 20))));
}