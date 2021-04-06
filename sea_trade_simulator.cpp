#include "Game.hpp"
#include <random>
#include <iostream>

constexpr int start_money = 1000;
constexpr int game_days = 100;
constexpr int final_goal = 2000;

int main() {
    Game game(start_money, game_days, final_goal);
    game.startGame();

    return 0;
}