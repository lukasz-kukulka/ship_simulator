#pragma once
#include <iostream>
#include "Time.hpp"
#include "Store.hpp"
#include "Map.hpp"
#include <memory>
#include <vector>
#include <string>

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
    void mapGenerate();
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
    std::vector<std::pair<std::pair<uint8_t, uint8_t>, std::string>> positions_; 
    std::shared_ptr<Map>map_;
};