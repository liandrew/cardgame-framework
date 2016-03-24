//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_PARTSFACTORY_H
#define CARD_GAME_FRAMEWORK_PARTSFACTORY_H

#include "Player.h"

class PartsFactory {
public:
   virtual Player makePlayer() = 0;
   virtual Player makeCPUPlayer() = 0;
   virtual Player makePile() = 0;
   virtual Player makeCard() = 0;
};

#endif //CARD_GAME_FRAMEWORK_PARTSFACTORY_H
