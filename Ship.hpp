#pragma once
#include <string>
#include <vector>
#include "Cargo.hpp"
#include "Item.hpp"
#include <memory>

class Ship
{
public:
    Ship();
    Ship(int, const std::string&, std::size_t, std::size_t, std::size_t);
    Ship(int, std::size_t, std::size_t);

    Ship& operator+=(const int);
    Ship& operator-=(const int crew);

    std::size_t getId() const { return id_; }
    std::string getName() const { return name_; }
    std::size_t getSpeed() const { return speed_; }
    std::size_t getMaxCrew() const { return maxCrew_; }
    std::size_t getCapacity() const { return capacity_; }
    //Cargo getCargo() { return *cargo_; }
    void setName(const std::string& name) { name_ = name; }
    void load(std::shared_ptr<Cargo>cargo);

private:
    //std::vector<std::shared_ptr<Cargo>> cargo_;
    int id_ { -1 };
    std::string name_;
    std::size_t speed_;
    std::size_t maxCrew_;
    std::size_t crew_;
    std::size_t capacity_;
};