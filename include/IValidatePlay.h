//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_IVALIDATEPLAY_H
#define CARD_GAME_FRAMEWORK_IVALIDATEPLAY_H

#include "Hand.h"

class IValidatePlay {
public:
    virtual bool isPlayable(Hand selection, Hand topPile) = 0;
    virtual bool isValid(Hand selection) = 0;
};

#endif //CARD_GAME_FRAMEWORK_IVALIDATEPLAY_H
