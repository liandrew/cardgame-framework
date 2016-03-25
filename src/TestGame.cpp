#include "../include/TestGame.h"
#include "../include/validateStrategies/Singles.h"

#include <iostream>

using namespace std;

TestGame::TestGame() : Game("Test Game"){
	_pile = new Pile("Pile");
	_winningPlayer = nullptr;
	setHandLimit(5);
	setMaxCardsPerPlay(5);

	shuffleDeck();

	for (int i = 0; i < _deck->size(); ++i) {
		cout << _deck->getCard(i)->toFullString() << endl;
	}
}

void TestGame::createPlayers() {
	_vPlayers.push_back(new TestPlayer("Player 1"));
	_vPlayers.push_back(new TestPlayer("Player 2"));
}

void TestGame::dealCards() {
	int handSize = getHandLimit();
	_deck->deal(_vPlayers[0]->getHand(), handSize);
	_deck->deal(_vPlayers[1]->getHand(), handSize);

	cout << "Starting " << getName() << endl;
	cout << "-----------------------------------" << endl;
}

bool TestGame::isWinner(Player &player) { // sorry i forgot to add player in parameter, it should make sense now
	if (!player.getHand().size()) {
		_winningPlayer = &player;
		setWinCondition();
		return true;
	}
	return false; // I don't really understand this function's usage
}

void TestGame::setWinCondition() {
	if (_winningPlayer) {
		setActive(false);
		cout << _winningPlayer->getName() << " wins!" << endl;
	}
}

void TestGame::playerAction(Player& player) {
	cout << "It's " << player.getName() << "'s Turn!" << endl;
	player.getHand().sort();
	cout << "Hand: " << player.getHand().toString() << endl;
	//player.play(player.getSelection(), _pile.getTopHand()); // Don't really understand how play() works yet, why is it making copies of hands?
	Singles singlesStrategy;
	player.setPlayable(singlesStrategy);

	std::cout << std::endl << "Pile: " << std::endl;
	std::cout << _pile->toString() << std::endl;
	std::cout <<  std::endl;

	player.makeSelection(getMaxCardsPerPlay());
	player.play(*_pile);
	isWinner(player);
}

TestPlayer::TestPlayer(std::string name) : Player(name) { }

bool TestPlayer::play(Hand selection, Hand playPile) {
	Card* card = _hand->getCard(0);
	_hand->transfer(playPile, 0);
	cout << "Transfered " << card->toFullString() << " to " << playPile.getType() << endl;
	return true;
}

TestGame::~TestGame() {
	if(_pile){
		delete _pile;
	}
}