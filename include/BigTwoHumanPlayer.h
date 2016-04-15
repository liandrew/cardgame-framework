//
// Created by Andrew on 2016-04-14.
//

#ifndef CARD_GAME_FRAMEWORK_BIGTWOHUMANPLAYER_H
#define CARD_GAME_FRAMEWORK_BIGTWOHUMANPLAYER_H

#include "Player.h"

class BigTwoHumanPlayer : public Player {
private:
    BigTwo_Singles singlesStrategy;
    BigTwo_Pairs pairsStrategy;
    BigTwo_Triples triplesStrategy;
    Poker pokerStrategy;
public:
    BigTwoHumanPlayer(std::string name);
    bool isHuman();
    std::string makeSelection(int playLimit, Pile& playPile);
    bool play(Pile& playPile, int handIndex = -1);
};

#endif //CARD_GAME_FRAMEWORK_BIGTWOHUMANPLAYER_H
