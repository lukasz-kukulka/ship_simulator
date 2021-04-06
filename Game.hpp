#pragma once
#include <iostream>

class Game{

public:
    Game(size_t, size_t, size_t);
    void startGame();
private:

    void printIntenface();
    void printMenu();

    size_t curentlyMoney_;
    size_t gameDays_;
    size_t gameGoal_;

};