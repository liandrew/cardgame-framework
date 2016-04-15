//
// Created by Andrew on 2016-04-15.
//

#ifndef CARD_GAME_FRAMEWORK_BIGTWODECK_H
#define CARD_GAME_FRAMEWORK_BIGTWODECK_H

#include "Deck.h"

class BigTwoDeck : public Deck {
public:
    BigTwoDeck(const std::string &type);
    void makeDeck();
};

#endif //CARD_GAME_FRAMEWORK_BIGTWODECK_H
