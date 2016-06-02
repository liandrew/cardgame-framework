//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_HAND_H
#define CARD_GAME_FRAMEWORK_HAND_H

#include "CardCollection.h"
#include "Card.h"

class Hand : public CardCollection {
public:
  bool concealTurned;

 Hand(const std::string &type);
 void sort();
 Card* findLargerThan(Card* card);
 Card* findSmallerThan(Card* card);
 Card* findSmallest();
 Card* findLargest();
 std::string toString();
};

#endif //CARD_GAME_FRAMEWORK_HAND_H
