//
// Created by Andrew on 2016-03-23.
//

#ifndef CARD_GAME_FRAMEWORK_PLAYER_H
#define CARD_GAME_FRAMEWORK_PLAYER_H

#include <iostream>
#include "Hand.h"
#include "Pile.h"
#include "IValidatePlay.h"
#include "validateStrategies/BigTwo_Singles.h"
#include "validateStrategies/BigTwo_Pairs.h"
#include "validateStrategies/BigTwo_Triples.h"
#include "validateStrategies/Poker.h"

class Player {
private:
    std::string _name;
    IValidatePlay* _pValidatePlay;
	// This will go into game specific sub classes for a3, for now it is here for testing purposes
    BigTwo_Singles singlesStrategy;
    BigTwo_Pairs pairsStrategy;
    BigTwo_Triples triplesStrategy;
    Poker pokerStrategy;
protected:
    Hand* _hand = NULL;
    Hand* _selection = NULL;
public:
    Player(std::string name);
    virtual std::string getName();
    virtual bool isHuman();
    void setPlayable(IValidatePlay& strategy);
    virtual bool isPlayable(Hand& selection, Hand& topPile);
    virtual bool makeSelection(int playLimit, Hand& topPile);
    virtual void clearSelection();
    virtual bool isValid(Hand& selection);
    virtual bool play(Pile& playPile, int handIndex = -1);
    Hand& getHand();
    Hand& getSelection();
    virtual ~Player();
};

#endif //CARD_GAME_FRAMEWORK_PLAYER_H
