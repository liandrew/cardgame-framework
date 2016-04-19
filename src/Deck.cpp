//
// Created by Andrew on 2016-03-24.
//

#include <string>
#include <ctime>
#include <map>
#include "../include/CardCollection.h"
#include "../include/Deck.h"
#include <cstdlib>

Deck::Deck(const std::string &type) : CardCollection(type){ }

void Deck::deal(CardCollection &hand, int handSize){
	transfer(hand, _vCards.size() - handSize, _vCards.size() - 1);
}

void Deck::shuffle(){
	std::srand(unsigned(std::time(NULL)));
	std::map<int, Card*> placed;
	unsigned int numberOfCards = _vCards.size();
	std::vector<Card*> oldDeck = _vCards;
	_vCards.clear();
	while (_vCards.size() < numberOfCards) {
		int place = (std::rand() % numberOfCards);
		while (placed[place]) place = (std::rand() % numberOfCards);
		Card* card = oldDeck[place];
		placed[place] = card;
		_vCards.push_back(card);
	}
}

Deck::~Deck() {
    for (int i = _vOriginal.size() - 1; i >= 0; --i) {
        delete _vOriginal[i];
    }
}

void Deck::makeDeck() {
    for(int suite=0; suite<= 3; suite++){
        for(int rank=1; rank<=13; rank++){
            addCard(new Card(rank,(Suite)suite));
        }
    }
    _vOriginal = _vCards;
}
