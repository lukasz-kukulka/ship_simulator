#include "Game.hpp"

Game::Game(size_t money, 
           size_t days, 
           size_t goal) : startMoney_(money), gameDays_(days), gameGoal_(goal){
    
}

void Game::startGame(){
    std::cout << "Game start\n";
}