//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_TRIPLES_H
#define CARD_GAME_FRAMEWORK_TRIPLES_H

#include "../IValidatePlay.h"
#include "../Hand.h"

class Triples : public IValidatePlay {
public:
    bool isPlayable(Hand selection, Hand topPile);
    bool isValid(Hand selection);
};

#endif //CARD_GAME_FRAMEWORK_TRIPLES_H
