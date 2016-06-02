#include "../include/TestGame.h"
#include <sstream>

using namespace std;

TestGame::TestGame() : Game("Test Solitaire Game"){
  _factory = new SolitaireFactory();
  _deck = _factory->makeDeck();

 _tableauSize = 7;
 _pileSelection = -1;

 _winningPlayer = nullptr;
 shuffleDeck();

 cout << "Testing shuffled deck contents: " << endl;
 cout << "-----------------------------------" << endl;
 for (int i = 0; i < _deck->size(); ++i) {
  cout << _deck->getCard(i)->toFullString() << endl;
}
cout << "-----------------------------------" << endl;
}

void TestGame::shuffleDeck(){
  _deck->shuffle();
}

void TestGame::createPlayers() {
  _vPlayers.push_back(_factory->makePlayer("Player"));
}

void TestGame::dealCards() {
  _pile = _factory->makePile();
  for (int i = 0; i < _tableauSize; ++i) {
    _deck->deal(_pile->get(i), i+1);
    for (int j = 0; j < i; ++j) {
      _pile->get(i).getCard(j)->setTurned(true);
    }
  }
  cout << "Starting " << getName() << endl;
  cout << "-----------------------------------" << endl;
}

bool TestGame::isWinner(Player &player) {
  Hand& diamonds = _pile->get(_tableauSize + (int)DIAMONDS);
  Hand& clubs = _pile->get(_tableauSize + (int)CLUBS);
  Hand& hearts = _pile->get(_tableauSize + (int)HEARTS);
  Hand& spades = _pile->get(_tableauSize + (int)SPADES);
  if (!diamonds.size() || !clubs.size() || !hearts.size() || !spades.size()) {
    return false;
  }
  if (diamonds.top()->getRankStr() == "A" &&
    clubs.top()->getRankStr() == "A" &&
    hearts.top()->getRankStr() == "A" &&
    spades.top()->getRankStr() == "A") {
    _winningPlayer = &player;
  setWinCondition();
  return true;
}
return false;
}

void TestGame::setWinCondition() {
  if (_winningPlayer) {
    setActive(false);
    cout << _winningPlayer->getName() << " wins!" << endl;
  }
}

 /*
 * Shows the tableau, and allows the player to place cards from their hand into a tableau.
 * Not implemented is transferring cards from your hand/a tableau to a foundation.
 */
void TestGame::playerAction(Player& player) {
  for (int i = 0; i < _tableauSize; ++i) {
    cout << _pile->get(i).getType() << ": " << _pile->get(i).toString() << endl;
  }

  if (player.getHand().size()) {
    cout << "Top card: " << player.getHand().top()->toString() << endl;
  }

  bool isPlayable = false;
  std::string selectedOption;
  std::string choice = "";

  do{
    Hand* currentHand = nullptr;
    if (player.getHand().size()) {
      cout << "Choose a tableau (1-7). Or d to Draw again. or q to quit." << endl;
    } else {
      cout << "Choose d to draw a card, or q to quit." << endl;
    }
    cin >> choice;
    if (choice == "q") {
      _isActive = false;
      isPlayable = true;
    } else if (choice == "d") {
      _deck->deal(_vPlayers[0]->getHand(), 1);
      cout << "Top card: " << player.getHand().top()->toString() << endl;
    } else if (player.getHand().size()) {
      _pileSelection = atoi(choice.c_str());
      _pileSelection -= 1;
      if (_pileSelection >= 0 && _pileSelection < 12) {
        currentHand = &_pile->get(_pileSelection);
      }

      Pile* selectedPile = new Pile("Temp Pile");
      selectedPile->setTopHand(*currentHand);

      selectedOption = player.makeSelection(getMaxCardsPerPlay(), *selectedPile);

      isPlayable = player.isPlayable(player.getSelection(), *selectedPile);

      if(selectedPile){
        delete selectedPile;
      }

      if (isPlayable) {
        player.play(*_pile, _pileSelection);
        isWinner(player);
      } else {
        std::cout << std::endl << "Invalid Move - try again" << std::endl << std::endl;
        player.clearSelection();
      }
    }
  } while(!isPlayable);
}

TestGame::~TestGame() {
  if (_pile) {
    delete _pile;
  }
  if (_factory) {
    delete _factory;
  }
}

SolitairePlayer::SolitairePlayer(std::string name) : Player(name) { }

bool SolitairePlayer::play(Pile& playPile, int handIndex) {
  Hand& hand = playPile[handIndex];
  _selection->transfer(hand, _selection->size() - 1);
  _hand->popCard();
  return true;
}

Player* SolitaireFactory::makePlayer(std::string name) {
  return new SolitairePlayer(name);
}

Pile* SolitaireFactory::makePile() {
  Pile* solitairePile = new Pile("Solitaire Pile");
  std::vector<Hand> pile;
  for (int i = 0; i < 7; ++i) {
    std::stringstream ss;
    ss << "Tableau #" << (i + 1);
    pile.push_back(Hand(ss.str()));
  }
  for (int i = 0; i < 4; ++i) {
    std::stringstream ss;
    ss << "Foundation #" << (i + 1);
    pile.push_back(Hand(ss.str()));
  }
  solitairePile->setPile(pile);
  return solitairePile;
}

std::string SolitairePlayer::makeSelection(int playLimit, Pile& playPile) {
  _selection->removeAll();
  if (_hand->size()) {
    _selection->addCard(_hand->top());
    return "valid";
  } else {
    return "invalid";
  }
}

bool SolitairePlayer::isPlayable(Hand& selection, Pile& pile) {
  Card* topCard = pile.getTopHand().top();
  int pileRank = topCard->getRank();
  if (pileRank == 1) pileRank = 14;
  return (selection.top()->getRank() == pileRank - 1);
}

void TestGame::setRules() {
  setMaxCardsPerPlay(1);
}

Deck* SolitaireFactory::makeDeck() {
  return new SolitaireDeck("Deck");
}

SolitaireCard::SolitaireCard(int rank, Suite suite, bool turned) : Card(rank, suite, turned) {
  _rank = rank;
  _suite = suite;
  _turned = turned;
}

std::string SolitaireCard::getRankStr() {
  return Card::getRankStr();
}

std::string SolitaireCard::getSuiteStr() {
  return Card::getSuiteStr();
}

std::string SolitaireCard::toString() {
  return Card::toString();
}

std::string SolitaireCard::toFullString() {
  return Card::toFullString();
}

SolitaireDeck::SolitaireDeck(const std::string &type) : Deck(type) {
  makeDeck();
}

void SolitaireDeck::makeDeck() {
  for(int suite=0; suite<= 3; suite++){
    for(int rank=1; rank<=13; rank++){
      addCard(new SolitaireCard(rank,(Suite)suite));
    }
  }
  _vOriginal = _vCards;
}

