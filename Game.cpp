#include "Game.hpp"

#include <iomanip> 
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <thread>

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
                player_(std::make_shared<Player>(time_.get())){
    mapGenerate();
}

void Game::startGame(){
    welcomeScreen();
    while (choiceAction() == true){
    }

}

void Game::cleanScreen(){
    std::system("clear");
    printIntenface();
}
// void Game::printMiniMap(){
// }

void Game::waitingForPressEnter(){
    std::cout << "Press ENTER to continue.";
    std::cin.clear();
    std::cin.ignore();
    std::cin.get();
    cleanScreen();
}

void Game::welcomeScreen(){
    std::system("clear");
    std::cout << "############################################################\n";
    std::cout << "#                                                          #\n";
    std::cout << "#         WELCOME TO TRADE SHIP SIMULATOR 1.0.0.0          #\n";
    std::cout << "#                                                          #\n";
    std::cout << "############################################################\n";
    waitingForPressEnter();
}

void Game::travel(){
    while (correctCoordination_ == false){
        std::cout << "Put coorditnation to travel: Witdh: ";
        std::cin >> travelCoordinate_.first;
        std::cout << "Put coorditnation to travel: Height: ";
        std::cin >> travelCoordinate_.second;
        std::cout << "\n";
        correctCoordination_ = checkTravelCoordination();
    }
    countTravelDistance();
    moveToCoordinate();
    travelCoordinate_ = {0, 0};
    correctCoordination_ = false;
}

bool Game::ifPlayerInIsland(){
    if (map_->getIsland(Coordinates(player_->getPlayerPosition().getPositionX() - 1, player_->getPlayerPosition().getPositionY() - 1 )) == nullptr){
        errorMessage = "You are not in any Island\n";
        return false;
    } else {
        return true;
    }
}

void Game::moveToCoordinate(){
    auto mapChangeIndex = (player_->getPlayerPosition().getPositionX() - 1) + (10 * (player_->getPlayerPosition().getPositionY() - 1));
    while (true){
        std::cout << "Your travel will go on " << travelDistance_.first + travelDistance_.second << " days.\n";
        std::cout << "Are you sure do you wanna continue? Y/N : ";
        std::cin >> answer;
        if (answer == "Y" || answer == "y"){
            if(map_->getIsland(Coordinates(player_->getPlayerPosition().getPositionX() - 1, player_->getPlayerPosition().getPositionY() - 1 )) == nullptr){
                positions_[mapChangeIndex].second = "|   |";
            } else {
                positions_[mapChangeIndex].second = "| O |" ;
            }
            player_->setPlayerPosition(travelCoordinate_.first, travelCoordinate_.second);
            *time_ += static_cast<int>(travelDistance_.first + travelDistance_.second);
            shipAnimation();
            mapChangeIndex = (player_->getPlayerPosition().getPositionX() - 1) +  (10 * (player_->getPlayerPosition().getPositionY() - 1));
            positions_[mapChangeIndex].second = "|[@]|";
            break;
        } else if (answer == "N" || answer == "n"){
            break;
        } else {
            std::system("clear");
            std::cout << "Wrong answer, please insert Y or N. \n";
        }
    }
}

bool Game::checkTravelCoordination(){
    if (travelCoordinate_.first > map_size.first || travelCoordinate_.second > map_size.second){
        std::cout << "Wrong value. Maximum width = " << map_size.first << ". Maximum width = " << map_size.second << ".\n";
        return false;
    } 
    if (travelCoordinate_.first ==  static_cast<int>(player_->getPlayerPosition().getPositionX()) && travelCoordinate_.second == static_cast<int>(player_->getPlayerPosition().getPositionY())){
        std::cout << "You will stay in the same position";
        return false;
    }
    if (travelCoordinate_.first < 0 || travelCoordinate_.second < 0){
        std::cout << "Wrong value, value can't be less then 0";
        return false;
    }
    return true;
}

void Game::countTravelDistance(){
    travelDistance_.first = std::abs(static_cast<int>(player_->getPlayerPosition().getPositionX() - travelCoordinate_.first)); 
    travelDistance_.second = std::abs(static_cast<int>(player_->getPlayerPosition().getPositionY() - travelCoordinate_.second));
}

void Game::shipAnimation(){
    std::string loadingStart = " ";
    std::string loadingEnd;
    int loopSize = ((3 * (travelDistance_.first + travelDistance_.second)) + 10);
    loadingEnd.assign(loopSize, ' ');
    for (int i = 0; i < loopSize; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cleanScreen();
        loadingStart.push_back(' ');
        loadingEnd.erase(loadingEnd.size() - 1);
        std::cout << loadingStart << "          4        " << loadingEnd << "######################" << "\n";
        std::cout << loadingStart << "         /|        " << loadingEnd << "#                    #" << "\n";
        std::cout << loadingStart << "        / |        " << loadingEnd << "#                    #" << "\n";
        std::cout << loadingStart << "       /  |        " << loadingEnd << "#       ISLAND       #" << "\n";
        std::cout << loadingStart << "      /   |        " << loadingEnd << "#                    #" << "\n";
        std::cout << loadingStart << "     /____|        " << loadingEnd << "#                    #" << "\n";
        std::cout << loadingStart << " _________|________" << loadingEnd << "#                    #" << "\n";
        std::cout << loadingStart << "|_________________/" << loadingEnd << "######################" << "\n";
    }
    messageAfterShipAnimation();
    cleanScreen();
}

void Game::messageAfterShipAnimation(){
    std::cout << "You arrived, you spend " << travelDistance_.first + travelDistance_.second << " days in your jorney\n";
    waitingForPressEnter();
}

void Game::checkEnterDataTransaction(){
    choiceCargoNumber_ = 0;
    choiceCargoQuantity_ = 0;
    do {
        std::cout << "Cargo number : \n" ;
        std::cin >> choiceCargoNumber_;
    } while(store_->checkCargoCondition(choiceCargoNumber_) == false);

    do {
        std::cout << "Cargo quantity : \n";
        std::cin >> choiceCargoQuantity_;
    } while(store_->checkCargoRange(choiceCargoQuantity_) == false);
}

void Game::buy(){
    checkEnterDataTransaction();
    if (store_->buy(store_->getCargo(static_cast<uint16_t>(choiceCargoNumber_)), choiceCargoQuantity_, player_.get()) == Store::Response::done){
        std::shared_ptr<Cargo>cargoTemp(store_->getCargo(static_cast<uint16_t>(choiceCargoNumber_)));
        player_->loadShip(cargoTemp);
        std::cout << "Transaction approved\n";
    }
}

void Game::sell(){
    checkEnterDataTransaction();
    store_->sell(store_->getCargo(static_cast<uint16_t>(choiceCargoNumber_)), choiceCargoQuantity_, player_.get());
    std::shared_ptr<Cargo>cargoTemp(store_->getCargo(static_cast<uint16_t>(choiceCargoNumber_)));
    player_->unloadShip(cargoTemp);
    std::cout << "Transaction approved\n";
}

void Game::printIntenface(){
    std::cout << std::setw (99) << std::setfill('#') << "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (97) << "#" << "\n";
    std::cout << "#" << std::setfill(' ') << std::setw (15) << "YOUR MONEY: " << std::setw (8) << std::setfill('0') << curentlyMoney_;
    std::cout << std::setfill(' ') << std::setw (30) << "YOUR GOAL: " << std::setw (8) << std::setfill('0') << gameGoal_;
    std::cout << std::setfill(' ') << std::setw (30) << "DAYS LEFT: " << std::setw (3) << std::setfill('0') << gameDays_ - time_->getElapseTime() << std::setfill(' ') << std::setw (4) << "#" "\n";
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
    std::cout << "#" << std::setfill(' ')  << std::setw (21) << " 4. SHIP CARGO " << std::setw (9) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (20) << " 5. SHOW MAP " << std::setw (10) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (19) << " 6. TRAVEL " << std::setw (11) << "#\n";
    std::cout << "#" << std::setfill(' ')  << std::setw (17) << " 7. EXIT" << std::setw (13) << "#\n";
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
    waitingForPressEnter();
    cleanScreen();
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
        if(player_->getPlayerPosition().getPositionX() - 1 == tempPosX && player_->getPlayerPosition().getPositionY() - 1 == tempPosY){
            positions_.push_back(std::make_pair(std::make_pair(tempPosX, tempPosY), "|[@]|"));
        } else if(map_->getIsland(Coordinates(tempPosX, tempPosY)) == nullptr){
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

bool Game::exitGame(){
    while(true){
        std::cout << "Are you sure you wanna quit the game? Y/N ";
        std::cin >> answer;
        if (answer == "Y" || answer == "y"){
            std::system("clear");
            return true;
        } else if (answer == "N" || answer == "n"){
            return false;
        } else {
            std::system("clear");
            std::cout << "Wrong answer, please insert Y or N. \n";
        }
    }
}

bool Game::choiceAction(){
    bool rightChoose = true;
    
    printMenu();
    std::cout << errorMessage << "YOUR CHOOSE: ";
    std::cin >> optionMenu_;
    errorMessage = "";
    menuOption_ = static_cast<Game::MenuOption>(optionMenu_);
    cleanScreen();
    switch (menuOption_)
    {
        case MenuOption::check_cargo : {
            if (ifPlayerInIsland() == true){
                std::cout << *store_ << "\n";
            }
        } break;
        case MenuOption::buy : {
            if (ifPlayerInIsland() == true){
                buy();
            }
        } break;
        case MenuOption::sell : {
            if (ifPlayerInIsland() == true){
                sell();
            }
        } break;
        case MenuOption::ship : {
            player_->printShipCargo();
        } break;
        case MenuOption::show_map : {
            printMap();
        } break;
        case MenuOption::travel : {
            travel();
        } break;
        case MenuOption::exit : {
            if (exitGame() == true){
                rightChoose = false;
            } else {
                rightChoose = true;
            }
        } break;
        default : {
            rightChoose = false; // add checker to answer about menu option
        } break;
    }
    return rightChoose;
}

void Game::checkShip(){
    
}
