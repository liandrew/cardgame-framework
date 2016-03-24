//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_SINGLES_H
#define CARD_GAME_FRAMEWORK_SINGLES_H

#include "../IValidatePlay.h"
#include "../Hand.h"

class Singles : public IValidatePlay {
public:
    bool isPlayable(Hand selection, Hand topPile);
    bool play(Hand selection, Hand playPile);
};

#endif //CARD_GAME_FRAMEWORK_SINGLES_H
