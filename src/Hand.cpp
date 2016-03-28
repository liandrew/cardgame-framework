//
// Created by Andrew on 2016-03-24.
//

#include <string>
#include "../include/CardCollection.h"
#include "../include/Hand.h"

Hand::Hand(const std::string &type) : CardCollection(type){
    concealTurned = true;
}

void Hand::sort(){
	int n = this->size();
	Hand temp("");
	for (unsigned int i = n - 1; i > 0; i--) {
		for (unsigned int j = 0; j < i; j++) {
			if (_vCards[j]->getRank() > _vCards[j+1]->getRank()) {
				temp.addCard(this->getCard(j));
				this->addCard(j, this->_vCards[j+1]);
				this->addCard(j + 1, temp.popCard());
			}
		}
	}
}

Card* Hand::findLargerThan(Card* card){
	int rank = card->getRank();
	for (unsigned int i = _vCards.size() - 1; i >= 0; --i) {
		if (_vCards[i]->getRank() > rank) {
			return _vCards[i];
		}
	}
	return nullptr;
}

Card* Hand::findSmallerThan(Card* card){
	int rank = card->getRank();
	for (unsigned int i = _vCards.size() - 1; i >= 0; --i) {
		if (_vCards[i]->getRank() < rank) {
			return _vCards[i];
		}
	}
	return nullptr;
}

Card* Hand::findSmallest(){
	Card* smallest = nullptr;
	for (unsigned int i = _vCards.size() - 1; i >= 0; --i) {
		if (!smallest || _vCards[i]->getRank() < smallest->getRank()) {
			smallest = _vCards[i];
		}
	}
	return smallest;
}

Card* Hand::findLargest(){
	Card* largest = nullptr;
	for (unsigned int i = _vCards.size() - 1; i >= 0; --i) {
		if (!largest || _vCards[i]->getRank() < largest->getRank()) {
			largest = _vCards[i];
		}
	}
	return largest;
}

std::string Hand::toString(){
	std::string handStr = "";
	for (unsigned int i = 0; i < _vCards.size(); ++i) {
        if (concealTurned && _vCards[i]->getTurned()) {
            handStr += "[ * ]";
        } else {
            handStr += _vCards[i]->toString();
        }
        if (i < _vCards.size() - 1) handStr += " ";
	}
	return handStr;
}