//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_PAIRS_H
#define CARD_GAME_FRAMEWORK_PAIRS_H

#include "../IValidatePlay.h"
#include "../Hand.h"
#include "../Pile.h"

class BigTwo_Pairs : public IValidatePlay {
public:
    bool isPlayable(Hand& selection, Pile& topPile);
    bool isValid(Hand& selection);
};

#endif //CARD_GAME_FRAMEWORK_PAIRS_H
