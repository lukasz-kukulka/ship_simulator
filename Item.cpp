#include "Item.hpp"


std::size_t Item::getPrice() const{
    switch (itemRarity) {
      case common: {
          return price_;
         break;
      }
      case rare: {
          return price_ * 2;
         break;
      }
      case epic: {
          return price_ * 4;
         break;
      }
      case legendary: {
          return price_ * 8;
         break;
      }
      default:
        return 0;
         break;
    }
}