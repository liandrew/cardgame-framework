//
// Created by Andrew and Jesse on 2016-03-23.
//

#include "../include/CardCollection.h"
#include "../include/Card.h"

CardCollection::CardCollection(std::string type){
    _collectionType = type;
}

CardCollection::~CardCollection() {
    //clear(); // commenting out for now since causing memory issues
}

void CardCollection::transfer(CardCollection& to, int index){
	if (index >= 0) {
		Card* card = getCard(index);
		removeCard(index);
		to.addCard(card);
	}
}

void CardCollection::transfer(CardCollection& to, int start, int end){
	if (start >= 0 && (unsigned int)end < _vCards.size()) {
		for (int i = end; i >= start; --i) {
			to.addCard(_vCards[i]);
		}
		_vCards.erase(_vCards.begin() + start, _vCards.begin() + end + 1);
	}
}

void CardCollection::transferAll(CardCollection& to){
	transfer(to, 0, _vCards.size());
}

int CardCollection::size(){
	return _vCards.size();
}

Card* CardCollection::getCard(int index){
	return _vCards[index];
}

Card* CardCollection::top(){
	return _vCards.size() ? _vCards[_vCards.size() - 1] : nullptr;
}

Card* CardCollection::last(){
	return _vCards.size() ? _vCards[0] : nullptr;
}

Card * CardCollection::operator[](int index) {
	return getCard(index);
}

void CardCollection::removeCard(int index){
	_vCards.erase(_vCards.begin() + index);
}

void CardCollection::removeFromCardCollection(CardCollection& from){
	std::vector<Card*>::iterator it = _vCards.begin();
	int size=from.size();
    for(int i=0; i < _vCards.size(); i++){
		for(int i=0; i<from.size(); i++){
			if(from.getCard(i)->getRank()==(*it)->getRank()
			   && from.getCard(i)->getSuite()==(*it)->getSuite()){
				removeCard(i);
			}
		}
	}
}

void CardCollection::removeAll(){
	_vCards.clear();
}

void CardCollection::clear() {
	for (int i = _vCards.size() - 1; i >= 0; --i) {
		delete _vCards[i];
	}
	_vCards.clear();
}

int CardCollection::findIndex(Card * card) {
	int index = -1;
	int cardSize = _vCards.size() - 1;
	for (int i = _vCards.size() - 1; i >= 0; --i) {
		if (_vCards[i] == card) {
			index = i;
			break;
		}
	}
	return index;
}

void CardCollection::addCard(Card * card) {
	_vCards.push_back(card);
}

std::string CardCollection::getType() {
	return _collectionType;
}

void CardCollection::addCard(int index, Card* card) {
	_vCards[index] = card;
}

Card* CardCollection::popCard(){
	Card* topCard = _vCards.back();
	_vCards.pop_back();
	return topCard;
}
