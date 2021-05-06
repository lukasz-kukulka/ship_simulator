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

int Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs){
	int distance = abs(static_cast<int>(lhs.positionX_) - static_cast<int>(rhs.positionX_)) + 
				   abs(static_cast<int>(lhs.positionY_) - static_cast<int>(rhs.positionY_));
	return distance;
}

void Coordinates::setCoordinates(int posX, int posY){
	positionX_ = posX;
	positionY_ = posY;
} 