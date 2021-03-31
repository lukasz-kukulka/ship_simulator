#include "Game.hpp"
#include "Ship.hpp"
#include <memory>

Game::Game(size_t money, 
           size_t days, 
           size_t goal) : startMoney_(money), gameDays_(days), gameGoal_(goal){
    
}

void Game::startGame(){
    std::cout << "Game start\n";
    // std::shared_ptr<Ship> ship1 = std::make_shared<Ship>();
    // std::cout << ship1->getCrew() << "<----- crew\n";
}