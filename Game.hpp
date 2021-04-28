#pragma once
#include "Time.hpp"
#include "Store.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Cargo.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <utility>

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
    void printRowInMap(uint8_t, std::string);
    void printIndexNumbers();
    void buy();
    void sell();
    void checkEnterDataTransaction();
    bool winCondition() const;
    bool loseCondition() const;
    bool choiceAction();
    int curentlyMoney_;
    int gameDays_;
    int gameGoal_;
    int optionMenu_ { 0 };
    std::shared_ptr<Time>time_;
    std::shared_ptr<Store>store_;
    std::shared_ptr<Map>map_;
    std::shared_ptr<Player>player_;
    Cargo* cargo_;
    MenuOption menuOption_;
    std::vector<std::pair<std::pair<uint8_t, uint8_t>, std::string>> positions_;
    std::string choiceCargoNumber { 0 };
    uint16_t choiceCargoQuantity { 0 };
};