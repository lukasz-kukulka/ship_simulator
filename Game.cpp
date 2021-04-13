#include "Game.hpp"
#include "Ship.hpp"
#include "Cargo.hpp"
#include <iomanip> 
#include <utility>

constexpr std::pair<uint8_t, uint8_t> map_size (20, 20);

Game::Game(int money, 
           int days, 
           int goal) : curentlyMoney_(money), gameDays_(days), gameGoal_(goal), time_(std::make_shared<Time>()), testStore(time_.get()){
}

void Game::startGame(){
    printIntenface();
    chooseAction();
    //printMenu();
    //std::cout << testStore << "\n";
    //++(*time_);
    //std::cout << testStore << "\n";

}

void Game::printIntenface(){
    std::cout << std::setw (99) << std::setfill('#') << "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (97) << "#" << "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (15) << "YOUR MONEY: " << std::setw (8) << std::setfill('0') << curentlyMoney_;
    std::cout << std::setfill(' ') << std::setw (30) << "YOUR GOAL: " << std::setw (8) << std::setfill('0') << gameGoal_;
    std::cout << std::setfill(' ') << std::setw (30) << "DAYS LEFT: " << gameDays_ << std::setw (4) << "#" "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (97) << "#" << "\n";
    std::cout << std::setw (99) << std::setfill('#') << "\n";
}

void Game::printMenu(){
    std::cout << "#" << std::setfill('-')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (22) << " CHOOSE ACTION: " << std::setw (8) << "#\n";
    std::cout << "#" << std::setfill('-')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (22) << " 1. CHECK CARGO " << std::setw (8) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (18) << " 2. BUY " << std::setw (12) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (18) << " 3. SELL " << std::setw (12) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (20) << " 4. SHOW MAP " << std::setw (10) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 5. TRAVEL " << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (17) << " 6. EXIT" << std::setw (13) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (30) << "#\n";
    std::cout << "#" << std::setfill('-')  << std::setw (31) << "#\n\n";
}

void Game::printMap(){

}

bool Game::winCondition() const{
    return curentlyMoney_ > gameGoal_;
}
bool Game::loseCondition() const{
    return ((curentlyMoney_ < gameGoal_ && time_->getElapseTime() >= static_cast<int>(gameDays_)) || (curentlyMoney_ <= 0));
}

bool Game::chooseAction(){
    bool rightChoose = true;
    std::cout << "YOUR CHOOSE: ";
    std::cin >> optionMenu_;
    menuOption_ = static_cast<Game::MenuOption>(optionMenu_);
    switch (menuOption_)
    {
        case MenuOption::check_cargo : {
            std::cout << testStore << "\n";
        } break;
        case MenuOption::buy : {
            //testStore.buy();
        } break;
        case MenuOption::sell : {
            //testStore.sell();
        } break;
        case MenuOption::show_map : {
            //showMap();
        } break;
        case MenuOption::travel : {
            //travel();
        } break;
        case MenuOption::exit : {
            //exit();
        } break;
        default : {
            rightChoose = false;
        } break;
    }
    return rightChoose;
}