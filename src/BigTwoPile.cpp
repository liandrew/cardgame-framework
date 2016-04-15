//
// Created by Andrew on 2016-04-15.
//

#include <iosfwd>
#include "../include/BigTwoPile.h"

BigTwoPile::BigTwoPile(std::string type) : Pile(type) {
    _type = type;
}

std::string BigTwoPile::toString(){
    std::string result = "";
    std::vector<Hand>::iterator it = Pile::_vPile.begin();
    for(; it != Pile::_vPile.end(); ++it) {
        result = (result=="" ? result : result + " | ") + (*it).toString();
    }
    return result;
}