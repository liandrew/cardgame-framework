//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_PARTSFACTORY_H
#define CARD_GAME_FRAMEWORK_PARTSFACTORY_H

#include "Player.h"
#include "Deck.h"

class PartsFactory {
public:
    virtual Player* makePlayer(std::string name) = 0;
    virtual Player* makeCPUPlayer(std::string name) = 0;
    virtual Pile* makePile() = 0;
    virtual Deck* makeDeck() = 0;
};

#endif //CARD_GAME_FRAMEWORK_PARTSFACTORY_H
