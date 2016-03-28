#include "../include/TestGame.h"
#include <iostream>
#include <sstream>

using namespace std;

TestGame::TestGame() : Game("Test Solitaire Game"){
    _factory = new SolitaireFactory();
    _tableauSize = 7;
    _pileSelection = -1;

	_winningPlayer = nullptr;
	setMaxCardsPerPlay(1);

	shuffleDeck();

    cout << "Testing shuffled deck contents: " << endl;
    cout << "-----------------------------------" << endl;
	for (int i = 0; i < _deck->size(); ++i) {
		cout << _deck->getCard(i)->toFullString() << endl;
	}
    cout << "-----------------------------------" << endl;
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
	bool isValid = false;
    std::string choice = "";

	do{
        Hand* currentHand = nullptr;
        if (player.getHand().size()) {
            cout << "Choose a tableau (1-7). Or d to Draw again" << endl;
        } else {
            cout << "Choose d to draw a card." << endl;
        }
        cin >> choice;
        if (choice == "d") {
            _deck->deal(_vPlayers[0]->getHand(), 1);
            cout << "Top card: " << player.getHand().top()->toString() << endl;
        } else if (player.getHand().size()) {
            _pileSelection = atoi(choice.c_str());
            _pileSelection -= 1;
            if (_pileSelection >= 0 && _pileSelection < 12) {
                currentHand = &_pile->get(_pileSelection);
            }

            isValid = player.makeSelection(getMaxCardsPerPlay());

            isPlayable = player.isPlayable(player.getSelection(), _pile->get(_pileSelection));

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

bool SolitairePlayer::makeSelection(int playLimit) {
    _selection->removeAll();
    if (_hand->size()) {
        _selection->addCard(_hand->top());
        return true;
    } else {
        return false;
    }
}

bool SolitairePlayer::isPlayable(Hand& selection, Hand& pile) {
    int pileRank = pile.top()->getRank();
    if (pileRank == 1) pileRank = 14;
    return (selection.top()->getRank() == pileRank - 1);
}
