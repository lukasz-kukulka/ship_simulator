#pragma once
#include <iostream>
#include "Time.hpp"
#include "Store.hpp"
#include <memory>

class Game{

public:
    Game(int, int, int);                           
    void startGame();

    enum class MenuOption : uint8_t {
        check_cargo = 1,
        buy,
        sell,
        show_map,
        travel,
        exit
    };
private:

    void printIntenface();
    void printMenu();
    void printMap();
    bool winCondition() const;
    bool loseCondition() const;
    bool chooseAction();
    int curentlyMoney_;
    int gameDays_;
    int gameGoal_;
    int optionMenu_ { 0 };
    std::shared_ptr<Time>time_;
    Store testStore;
    MenuOption menuOption_;
};