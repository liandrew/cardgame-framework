//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_GAME_H
#define CARD_GAME_FRAMEWORK_GAME_H

#include "Player.h"
#include "Deck.h"
#include "PartsFactory.h"

class Game {
private:
    std::string _name;
    std::string _description;
	bool _isActive;
    int _playLimit;
    int _handLimit;
    int _maxPlayers;
    int _CPUPlayers;
	int _playerTurn;
	int _gameTurn;
protected:
    std::vector<Player*> _vPlayers;
    Deck* _deck = NULL;
public:
    Game(std::string name);

    void createGame(); // template method

    void setMaxCardsPerPlay(int limit);
    int getMaxCardsPerPlay();
    void setHandLimit(int handLimit);
    int getHandLimit();
    void setMaxPlayers(int playerLimit);
    int getMaxPlayers();
    void setNumberOfCPUPlayers(int num);
    int getNumberOfCPUPlayers();
    void setDescription(std::string);
    std::string getDescription();
    void setName(std::string);
    std::string getName();

    void shuffleDeck();
	bool isActive();
	void setActive(bool active);

	virtual void gameLoop();

	virtual void playerAction(Player& player) = 0;
	virtual void createPlayers() = 0;
    virtual void dealCards() = 0; // deal cards for solitary game has different behavior
    virtual bool isWinner() = 0;
    virtual void setWinCondition() = 0;
    virtual Player& getCurrentPlayer();
	int getTurn();

    ~Game(){
        if(_deck){
            delete _deck;
        }
    };
};

#endif //CARD_GAME_FRAMEWORK_GAME_H
