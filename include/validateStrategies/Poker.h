//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_POKER_H
#define CARD_GAME_FRAMEWORK_POKER_H

#include "../IValidatePlay.h"
#include "../Hand.h"
#include "../IPokerValidatePlay.h"
#include "../Pile.h"
#include "../pokerStrategies/StraightFlush.h"
#include "../pokerStrategies/FourOfAKind.h"
#include "../pokerStrategies/FullHouse.h"
#include "../pokerStrategies/Straight.h"

enum PokerHand { INVALID, STRAIGHT, FLUSH, FULLHOUSE, FOUROFAKIND, STRAIGHTFLUSH};

class Poker : public IValidatePlay {
private:
    IPokerValidatePlay* _pValidatePokerPlay;
    StraightFlush _straightFlushStrategy;
    FourOfAKind _fourOfAKindStrategy;
    FullHouse _fullhouseStrategy;
    Straight _straightStrategy;
public:
    void setPokerPlayable(IPokerValidatePlay& strategy);
    bool isPokerPlayable(Hand& selection, Pile& playPile);
    PokerHand isPokerValid(Hand& selection);
	 //Checks if selected hand can be played against the top pile hand
    bool isPlayable(Hand& selection, Pile& playPile);
    bool isValid(Hand& selection);
};

#endif //CARD_GAME_FRAMEWORK_POKER_H
