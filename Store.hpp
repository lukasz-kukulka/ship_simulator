#pragma once
#include "Player.hpp"
#include "Cargo.hpp"

class Store{
public:
    Store(size_t, size_t);

    enum class Response {done, lack_of_money, lack_of_cargo, lack_of_space};

    Response buy(Cargo*, size_t, Player*);
    Response sell(Cargo*, size_t, Player*);
    void printMessage();
    bool checkMoney(size_t, size_t, size_t);
    bool checkCargo(size_t, size_t);
    bool checkSpace(size_t, size_t);
    size_t getPrice() { return itemPrice_; }
    size_t getQuantity() { return itemQuantity_; }

    //void generateRandomPrice();
    
    

private:
    Response tradeStatus;
    size_t positionX_;
    size_t positionY_;
    std::string name_;
    size_t itemPrice_;
    size_t itemQuantity_;


};
