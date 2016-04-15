//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_FLUSH_H
#define CARD_GAME_FRAMEWORK_FLUSH_H

#include "../IPokerValidatePlay.h"
#include "../Hand.h"

class Flush : public IPokerValidatePlay {
public:
  bool isPokerPlayable(Hand& selection, Pile& topPile);
};

#endif //CARD_GAME_FRAMEWORK_FLUSH_H
