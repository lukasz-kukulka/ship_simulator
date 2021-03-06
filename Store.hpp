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

    //override Observer
    ~Store() override;
    void nextDay() override;
    
    enum class Response : uint8_t {
        done, 
        lack_of_money, 
        lack_of_cargo, 
        lack_of_space
    };

    Response buy(Cargo*, size_t, Player*);
    Response sell(Cargo*, size_t, Player*);
    friend std::ostream& operator<<(std::ostream&, const Store&);
    bool checkCargoCondition(int);
    bool checkCargoRange(uint16_t);
    Cargo* getCargo(uint16_t);

private:
    uint16_t getNoOffCargo() { return static_cast<uint16_t>(cargo_.size()); }
    void generateAllCargo();
    void generateAlcohol();
    void generateItems();
    void generateFruits();
    void generateDryFruits();
    void printMessage();
    bool checkMoney(size_t, size_t, size_t);
    bool checkCargo(size_t, size_t);
    bool checkSpace(size_t, size_t);
    size_t randomGenerate(int, int);
    void buyGenerateItemStatus(Cargo*, size_t, Player*);
    bool ifCargoExist(Cargo*);
    std::vector<std::shared_ptr<Cargo>>cargo_;
    Response tradeStatus_;
    std::string messageError_ { "" };
    uint16_t numberCargoToCheck { 0 };
    int cargoSize;
    Time* time_;
};
