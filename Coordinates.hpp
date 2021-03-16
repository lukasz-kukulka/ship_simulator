#pragma once
#include <iostream>


class Coordinates
{

public:
    Coordinates(std::size_t, std::size_t);

    bool operator==(const Coordinates&) const;

    std::size_t getPositionX() const { return positionX_; }
    std::size_t getPositionY() const { return positionY_; }

private:
    std::size_t positionX_{}, positionY_{};

};

