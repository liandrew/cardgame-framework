//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_POKER_H
#define CARD_GAME_FRAMEWORK_POKER_H

#include "../IValidatePlay.h"
#include "../Hand.h"
#include "../IPokerValidatePlay.h"
#include "../Pile.h"

class Poker : public IValidatePlay {
public:
    void setPokerPlayable(IPokerValidatePlay& strategy);
    bool isPokerPlayable(Hand selection, Hand topPile);
    bool isValidPokerMove(Hand selection, Hand topPile);
    bool isPlayable(Hand selection, Hand topPile);
    bool isValidMove(Hand selection, Hand topPile);
};

#endif //CARD_GAME_FRAMEWORK_POKER_H
