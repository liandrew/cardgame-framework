//
// Created by Andrew on 2016-03-23.
//

#ifndef CARD_GAME_FRAMEWORK_PLAYER_H
#define CARD_GAME_FRAMEWORK_PLAYER_H

#include <iostream>
#include "Hand.h"
#include "Pile.h"
#include "IValidatePlay.h"

class Player {
private:
    std::string _name;
    IValidatePlay* _pValidatePlay;
protected:
    Hand* _hand;
    Hand* _selection;
public:
    Player(std::string name);
    virtual std::string getName();
    virtual bool isHuman();
    void setPlayable(IValidatePlay& strategy);
    virtual bool isPlayable(Hand selection, Hand topPile);
    virtual bool play(Hand selection, Hand playPile);
	Hand& getHand();
	Hand& getSelection();
    virtual ~Player();
};

#endif //CARD_GAME_FRAMEWORK_PLAYER_H
