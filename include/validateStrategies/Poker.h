//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_POKER_H
#define CARD_GAME_FRAMEWORK_POKER_H

#include "../IValidatePlay.h"
#include "../Hand.h"
#include "../IPokerValidatePlay.h"
#include "../Pile.h"

enum PokerHand { STRAIGHTFLUSH, FOUROFAKIND, FULLHOUSE, FLUSH, STRAIGHT, INVALID};

class Poker : public IValidatePlay {
private:
    IPokerValidatePlay* _pValidatePokerPlay;
    int getPokerHandIndex();
public:
    void setPokerPlayable(IPokerValidatePlay& strategy);
    bool isPokerPlayable(Hand selection, Hand topPile);
    PokerHand isPokerMoveValid(Hand selection);
    bool isPlayable(Hand selection, Hand topPile);
    bool isValidMove(Hand selection, Hand topPile);
};

#endif //CARD_GAME_FRAMEWORK_POKER_H
