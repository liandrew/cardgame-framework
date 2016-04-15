//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_FOUROFAKIND_H
#define CARD_GAME_FRAMEWORK_FOUROFAKIND_H

#include "../IPokerValidatePlay.h"
#include "../Hand.h"
#include "../Pile.h"

class FourOfAKind : public IPokerValidatePlay {
public:
    bool isPokerPlayable(Hand& selection, Pile& playPile);
};

#endif //CARD_GAME_FRAMEWORK_FOUROFAKIND_H
