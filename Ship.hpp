#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Cargo.hpp"

class Ship
{
public:
    Ship(int, const std::string&, std::size_t, int, std::size_t);
    Ship(int, std::size_t, int);

    Ship& operator+=(const int);
    Ship& operator-=(const int);

    std::size_t getId() const { return id_; }
    std::string getName() const { return name_; }
    std::size_t getSpeed() const { return speed_; }
    std::size_t getMaxCrew() const { return maxCrew_; }
    std::size_t getCapacity() const { return capacity_; }
    //Cargo getCargo() { return *cargo_; }
    void setName(const std::string& name) { name_ = name; }
    void load(const std::shared_ptr<Cargo>);
    void unload(Cargo*);

private:
    std::vector<std::shared_ptr<Cargo>> cargo_;
    int id_ { -1 };
    std::string name_;
    std::size_t speed_;
    int maxCrew_;
    int crew_;
    std::size_t capacity_{ 1000 };
};