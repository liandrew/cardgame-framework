//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_SINGLES_H
#define CARD_GAME_FRAMEWORK_SINGLES_H

#include "../IValidatePlay.h"
#include "../Hand.h"

class BigTwo_Singles : public IValidatePlay {
public:
    bool isPlayable(Hand& selection, Pile& topPile);
    bool isValid(Hand& selection);
};

#endif //CARD_GAME_FRAMEWORK_SINGLES_H
