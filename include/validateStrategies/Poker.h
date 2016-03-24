//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_POKER_H
#define CARD_GAME_FRAMEWORK_POKER_H

#include "../IValidatePlay.h"
#include "../Hand.h"
#include "../IPokerValidatePlay.h"

class Poker : public IValidatePlay {
public:
    void setPokerPlayable(IPokerValidatePlay& strategy);
    bool isPlayable(Hand selection, Hand topPile);
    bool play(Hand selection, Hand playPile);
};

#endif //CARD_GAME_FRAMEWORK_POKER_H
