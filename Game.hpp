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
    int curentlyMoney_;
    int gameDays_;
    int gameGoal_;
    std::shared_ptr<Time>time_;
};