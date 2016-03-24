//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_IPOKERVALIDATEPLAY_H
#define CARD_GAME_FRAMEWORK_IPOKERVALIDATEPLAY_H

#include "Hand.h"

class IPokerValidatePlay {
public:
    virtual bool isPokerPlayable(Hand selection, Hand topPile) = 0;
    virtual bool playPoker(Hand selection, Hand playPile) = 0;
};

#endif //CARD_GAME_FRAMEWORK_IPOKERVALIDATEPLAY_H
