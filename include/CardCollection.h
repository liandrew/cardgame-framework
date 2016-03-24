//
// Created by Andrew on 2016-03-23.
//

#ifndef CARD_GAME_FRAMEWORK_CARDCOLLECTION_H
#define CARD_GAME_FRAMEWORK_CARDCOLLECTION_H

#include <vector>
#include <string>
#include "Card.h"

class CardCollection {
protected:
    std::vector<Card> _vCards;
private:
    std::string _collectionType;
public:
    CardCollection(std::string type);
    void transfer(CardCollection to, CardCollection from, int index);
    void transfer(CardCollection to, CardCollection from, int start, int end);
    void transferAll(CardCollection to, CardCollection from);
    int size();
    Card getCard(int index);
    Card top();
    Card last();
    void removeCard(int index);
    void removeAll();
    void addCard(Card card);
};

#endif //CARD_GAME_FRAMEWORK_CARDCOLLECTION_H
