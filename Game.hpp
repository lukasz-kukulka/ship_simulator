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
    void welcomeScreen();
    void printIntenface();
    void printMenu();
    void printMap();
    bool checkTravelCoordination();
    // void printMiniMap();
    void mapGenerate();
    void printRowInMap(uint8_t, std::string);
    void printIndexNumbers();
    void buy();
    void sell();
    void checkEnterDataTransaction();
    void travel();
    bool winCondition() const;
    bool loseCondition() const;
    bool choiceAction();
    void moveToCoordinate();
    void countTravelDistance();
    void shipAnimation();
    bool exitGame();
    bool ifPlayerInIsland();
    void waitingForPressEnter();
    void cleanScreen();
    void messageAfterShipAnimation();
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
    std::string choiceCargoNumber_ { 0 };
    uint16_t choiceCargoQuantity_ { 0 };
    std::pair<int, int>travelCoordinate_{0, 0};
    bool correctCoordination_ { false };
    std::pair<int, int>travelDistance_{1, 1}; //should me 0, 0 this value only for test
    bool progresShipAnimation_ { false };
    std::string answer {};
    std::string errorMessage {};
};