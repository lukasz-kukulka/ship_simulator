#include "Coordinates.hpp"


Coordinates::Coordinates(std::size_t positionX, 
                         std::size_t positionY) :  positionX_(positionX), positionY_(positionY)
{

}

bool Coordinates::operator==(const Coordinates& coordinates) const{
    if (positionX_ == coordinates.positionX_ && positionY_ == coordinates.positionY_) {
		return true;
	} else {
		return false;
	}
}
