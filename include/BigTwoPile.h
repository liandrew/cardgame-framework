//
// Created by Andrew on 2016-04-14.
//

#ifndef CARD_GAME_FRAMEWORK_BIGTWOPILE_H
#define CARD_GAME_FRAMEWORK_BIGTWOPILE_H

#include "Pile.h"

class BigTwoPile : public Pile {
public:
    BigTwoPile(std::string type);
    std::string toString();
};

#endif //CARD_GAME_FRAMEWORK_BIGTWOPILE_H
