#include "Game.hpp"
#include <random>
#include <iostream>

constexpr size_t start_money = 1'000;
constexpr size_t game_days = 100;
constexpr size_t final_goal = 2'000;

int main() {
    Game game(start_money, game_days, final_goal);
    game.startGame();
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 6);
    std::cout << distrib(gen) ;

    return 0;
}