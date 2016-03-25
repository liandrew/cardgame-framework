#ifndef TESTGAME_H
#define TESTGAME_H

#include "Game.h"
#include "Pile.h"

class TestPlayer : public Player {
public:
	TestPlayer(std::string name);
	bool isHuman() { return true; }
	bool play(Hand selection, Hand playPile);
};

class TestGame : public Game {
private:
	Pile* _pile = NULL;
	Player* _winningPlayer;
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