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
protected:
  Hand* _hand = NULL;
  Hand* _selection = NULL;
public:
  Player(std::string name);
  virtual std::string getName();
  virtual bool isHuman()=0;
  void setPlayable(IValidatePlay& strategy);
  virtual bool isPlayable(Hand& selection, Pile& playPile);
  virtual std::string makeSelection(int playLimit, Pile& playPile)=0;
  virtual void clearSelection();
  virtual bool isValid(Hand& selection);
  virtual bool play(Pile& playPile, int handIndex = -1)=0;
  Hand& getHand();
  Hand& getSelection();
  virtual ~Player();
};

#endif //CARD_GAME_FRAMEWORK_PLAYER_H
