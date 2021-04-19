#include "Game.hpp"
#include "Ship.hpp"

#include <iomanip> 
#include <algorithm>
#include <cctype>
#include <cstdlib>

constexpr std::pair<uint8_t, uint8_t> map_size (10, 10);

Game::Game(int money, 
           int days, 
           int goal) : 
                curentlyMoney_(money), 
                gameDays_(days),
                gameGoal_(goal), 
                time_(std::make_shared<Time>()), 
                store_(std::make_shared<Store>(time_.get())),
                map_(std::make_shared<Map>(map_size)),
                player_(std::make_shared<Player>()) {
    mapGenerate();
}

void Game::startGame(){
    buy();
    //printIntenface();
    //chooseAction();
    //printMap();
    //printMenu();
    //std::cout << testStore << "\n";
    //++(*time_);
    //std::cout << testStore << "\n";

}

void Game::transactionCargo(uint8_t typeTransaction, uint8_t amout){
    if (typeTransaction == 1 && amout == 1){
        store_->buy(cargo_, amout, player_.get());
    } else if (typeTransaction == 2){
        store_->sell(cargo_, amout, player_.get());
    }
}

void Game::buy(){
    std::string chose;
    std::cout << "Please put number cargo what you wanna buy: ";
    std::cin >> chose;
    auto results = std::find_if(begin(chose), end(chose), [&](auto element){ return !std::isdigit(static_cast<unsigned char>(element)); });
    if (results == chose.end() || static_cast<uint16_t>(std::stoi(chose)) > store_->getNoOffCargo()) {
        std::cout << "Wrong value, please insert correct number";
    } else {
        
    }
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
    printIndexNumbers();
    for (const auto& mapPosition : positions_){
        if (mapPosition.first.first == 0){
            std::cout << "    |";
            printRowInMap(map_size.first, "|---|");
            std::cout << "  " << std::setw (2) << std::setfill('0') << std::to_string(mapPosition.first.second + 1) << "|";
        }
        std::cout << mapPosition.second;
        if (mapPosition.first.first >= map_size.first - 1){
            std::cout <<"\n    |";
            printRowInMap(map_size.first, "|---|");
        }
    }
}

void Game::printRowInMap(uint8_t repeatTime, std::string whatRepeat){
    for (uint8_t i = 0; i < repeatTime; i++){
        std::cout << whatRepeat;
    }
    std::cout << "\n";
}

void Game::printIndexNumbers(){
    std::cout << "    |";
    for (uint8_t i = 0; i < (map_size.first); i++){
        std::cout << " " << std::setw (2) << std::setfill('0') << std::to_string(i + 1) << "  ";
    }
    std::cout <<"\n";
}

void Game::mapGenerate(){
    uint8_t tempPosX = 0, tempPosY = 0;
    std::cout << "\n";
    while (tempPosX < map_size.first && tempPosY < map_size.second){
        if(map_->getIsland(Coordinates(tempPosX, tempPosY)) == nullptr){
            positions_.push_back(std::make_pair(std::make_pair(tempPosX, tempPosY), "|   |"));
        } else {
            positions_.push_back(std::make_pair(std::make_pair(tempPosX, tempPosY), "| O |"));
        }
        tempPosX ++;
        if (tempPosX >= map_size.first){
            tempPosY++;
            tempPosX = 0;
        }
    }
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
            std::cout << store_ << "\n";
        } break;
        case MenuOption::buy : {
            //std::cin >> 
            //testStore.buy();
        } break;
        case MenuOption::sell : {
            //testStore.sell();
        } break;
        case MenuOption::show_map : {
            printMap();
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
