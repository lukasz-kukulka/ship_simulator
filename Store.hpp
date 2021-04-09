#pragma once
#include "Player.hpp"
#include "Cargo.hpp"
#include <string>
#include <memory>
#include "Obserwer.hpp"
#include "Time.hpp"

class Store : public Obserwer{
public:
    Store(Time*);
    ~Store() override;
    enum class Response : uint8_t {
        done, 
        lack_of_money, 
        lack_of_cargo, 
        lack_of_space
    };

    Response buy(Cargo*, size_t, Player*);
    Response sell(Cargo*, size_t, Player*);

    //override Observer
    void nextDay() override;
    friend std::ostream& operator<<(std::ostream&, const Store&);


private:

    void generateAllCargo();
    void generateAlcohol();
    void generateItems();
    void printMessage();
    bool checkMoney(size_t, size_t, size_t);
    bool checkCargo(size_t, size_t);
    bool checkSpace(size_t, size_t);
    size_t randomGenerate(int, int);
    //size_t getPrice() { return itemPrice_; }
    //size_t getQuantity() { return itemQuantity_; }
    void generateItemStatus(Cargo*, size_t, Player*);
    std::vector<std::shared_ptr<Cargo>>cargo_;
    Response tradeStatus_;
    //std::shared_ptr<Response>ptrStatus_ = std::make_shared<Response>(Response::done);
    std::string messageError_ { "" };

    Time* time_;
};
