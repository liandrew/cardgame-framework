//
// Created by Andrew on 2016-04-15.
//

#ifndef CARD_GAME_FRAMEWORK_BIGTWOGAME_H
#define CARD_GAME_FRAMEWORK_BIGTWOGAME_H

#include "Game.h"

class BigTwoGame : public Game {
    Pile* _pile = NULL;
    Player* _winningPlayer;
    PartsFactory* _factory;
public:
    BigTwoGame();
    void gameLoop();
    void playerAction(Player& player);
    void setRules();
    void createPlayers();
    void dealCards();
    bool isWinner(Player& player);
    void setWinCondition();
    Player& getCurrentPlayer();
    ~BigTwoGame();
};

#endif //CARD_GAME_FRAMEWORK_BIGTWOGAME_H
