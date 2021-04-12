#pragma once
#include <iostream>
#include "Time.hpp"
#include "Store.hpp"
#include <memory>

class Game{

public:
    Game(int, int, int);
    void startGame();
private:

    void printIntenface();
    void printMenu();
    bool winCondition() const;
    bool loseCondition() const;
    bool chooseAction();
    int curentlyMoney_;
    int gameDays_;
    int gameGoal_;
    uint8_t optionMenu_ { 0 };
    std::shared_ptr<Time>time_;
    Store testStore;
};