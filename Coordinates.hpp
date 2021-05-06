#pragma once
#include <iostream>


class Coordinates
{

public:
    Coordinates() = default;
    Coordinates(std::size_t, std::size_t);

    bool operator==(const Coordinates&) const;
    static int distance(const Coordinates&, const Coordinates&);
    void setCoordinates(int, int);
    std::size_t getPositionX() const { return positionX_; }
    std::size_t getPositionY() const { return positionY_; }

private:
    std::size_t positionX_{}, positionY_{};

};

