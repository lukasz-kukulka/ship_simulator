#include "Alcohol.hpp"


std::size_t Alcohol::getPrice() const {
    return price_ / maxPurity_ * purity_;
}