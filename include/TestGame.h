#ifndef TESTGAME_H
#define TESTGAME_H

#include "Game.h"
#include "Pile.h"
#include "BigTwoCard.h"

class SolitairePlayer : public Player {
public:
  SolitairePlayer(std::string name);
  bool isHuman() { return true; }
  bool play(Pile& playPile, int handIndex = -1);
  std::string makeSelection(int playLimit, Pile& playPile);
  bool isPlayable(Hand& selection, Pile& playPile);
};

class SolitaireFactory : public PartsFactory {
  Player* makePlayer(std::string name);
  Player* makeCPUPlayer(std::string name) { return nullptr; };
  Pile* makePile();
  Deck* makeDeck();
};

class SolitaireCard : public Card {
public:
  SolitaireCard(int rank, Suite suite, bool turned=false);
  std::string getRankStr();
  std::string getSuiteStr();
  std::string toString();
  std::string toFullString();
};

class SolitaireDeck : public Deck {
public:
  SolitaireDeck(const std::string &type);
  void makeDeck();
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
  void setRules();
  ~TestGame();

  void shuffleDeck();
};

#endif