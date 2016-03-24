//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_ROYALFLUSH_H
#define CARD_GAME_FRAMEWORK_ROYALFLUSH_H

#include "../IPokerValidatePlay.h"
#include "../Hand.h"

class RoyalFlush : public IPokerValidatePlay {
public:
    bool isPokerPlayable(Hand selection, Hand topPile);
    bool playPoker(Hand selection, Hand playPile);
};

#endif //CARD_GAME_FRAMEWORK_ROYALFLUSH_H
