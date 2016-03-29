//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_DECK_H
#define CARD_GAME_FRAMEWORK_DECK_H

#include "CardCollection.h"

class Deck : public CardCollection {
private:
    std::vector<Card*> _vOriginal;
public:
    virtual ~Deck();
    Deck(const std::string &type);
    void deal(CardCollection &hand, int handSize);
    void shuffle();
};

#endif //CARD_GAME_FRAMEWORK_DECK_H
