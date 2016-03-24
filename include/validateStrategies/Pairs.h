//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_PAIRS_H
#define CARD_GAME_FRAMEWORK_PAIRS_H

#include "../IValidatePlay.h"
#include "../Hand.h"

class Pairs : public IValidatePlay {
public:
    bool isPlayable(Hand selection, Hand topPile);
    bool play(Hand selection, Hand playPile);
};

#endif //CARD_GAME_FRAMEWORK_PAIRS_H