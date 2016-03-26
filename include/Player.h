//
// Created by Andrew on 2016-03-23.
//

#ifndef CARD_GAME_FRAMEWORK_PLAYER_H
#define CARD_GAME_FRAMEWORK_PLAYER_H

#include <iostream>
#include "Hand.h"
#include "Pile.h"
#include "IValidatePlay.h"
#include "validateStrategies/Singles.h"
#include "validateStrategies/Pairs.h"
#include "validateStrategies/Triples.h"
#include "validateStrategies/Poker.h"

class Player {
private:
    std::string _name;
    IValidatePlay* _pValidatePlay;
    Singles singlesStrategy;
    Pairs pairsStrategy;
    Triples triplesStrategy;
    Poker pokerStrategy;
protected:
    Hand* _hand = NULL;
    Hand* _selection = NULL;
public:
    Player(std::string name);
    virtual std::string getName();
    virtual bool isHuman();
    void setPlayable(IValidatePlay& strategy);
    virtual bool isPlayable(Hand selection, Hand topPile);
    virtual bool makeSelection(int playLimit);
    virtual void clearSelection();
    virtual bool isValid(Hand selection);
    virtual bool play(Pile& playPile);
    Hand& getHand();
    Hand& getSelection();
    virtual ~Player();
};

#endif //CARD_GAME_FRAMEWORK_PLAYER_H
