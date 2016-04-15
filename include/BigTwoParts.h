//
// Created by Andrew on 2016-04-14.
//

#ifndef CARD_GAME_FRAMEWORK_BIGTWOPARTS_H
#define CARD_GAME_FRAMEWORK_BIGTWOPARTS_H

#include "PartsFactory.h"
#include "BigTwoPile.h"
#include "BigTwoCard.h"
#include "BigTwoDeck.h"

class BigTwoParts : public PartsFactory {
public:
    Player* makePlayer(std::string name);
    Player* makeCPUPlayer(std::string name);
    BigTwoPile* makePile();
    BigTwoDeck* makeDeck();
    ~BigTwoParts();
};

#endif //CARD_GAME_FRAMEWORK_BIGTWOPARTS_H
