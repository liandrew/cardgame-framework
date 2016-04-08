#ifndef TESTGAME_H
#define TESTGAME_H

#include "Game.h"
#include "Pile.h"

class SolitairePlayer : public Player {
public:
    SolitairePlayer(std::string name);
    bool isHuman() { return true; }
    bool play(Pile& playPile, int handIndex = -1);
    bool makeSelection(int playLimit, Hand& topPile);
    bool isPlayable(Hand& selection, Hand& topPile);
};

class SolitaireFactory : public PartsFactory {
    Player* makePlayer(std::string name);
    Player* makeCPUPlayer(std::string name) { return nullptr; };
    Pile* makePile();
};

class TestGame : public Game {
private:
	Pile* _pile = NULL;
	Player* _winningPlayer;
    PartsFactory* _factory;
    int _tableauSize;
    int _pileSelection;
public: 
	TestGame();

	void createPlayers();
	void dealCards(); // deal cards for solitary game has different behavior
	bool isWinner(Player &player);
	void setWinCondition();
	void playerAction(Player& player);
	~TestGame();
};

#endif