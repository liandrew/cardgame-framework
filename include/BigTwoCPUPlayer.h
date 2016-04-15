//
// Created by Andrew on 2016-04-14.
//

#ifndef CARD_GAME_FRAMEWORK_BIGTWOCPUPLAYER_H
#define CARD_GAME_FRAMEWORK_BIGTWOCPUPLAYER_H

#include "Player.h"

class BigTwoCPUPlayer : public Player {
private:
    BigTwo_Singles singlesStrategy;
    BigTwo_Pairs pairsStrategy;
    BigTwo_Triples triplesStrategy;
    Poker pokerStrategy;
public:
    BigTwoCPUPlayer(std::string name);
    bool isHuman();
    std::string makeSelection(int playLimit, Pile& playPile);
    bool play(Pile& playPile, int handIndex = -1);
    bool isPlayable(Hand &selection, Pile &playPile);
    bool isValid(Hand &selection);
};

#endif //CARD_GAME_FRAMEWORK_BIGTWOCPUPLAYER_H
