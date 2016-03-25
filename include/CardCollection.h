//
// Created by Andrew on 2016-03-23.
//

#ifndef CARD_GAME_FRAMEWORK_CARDCOLLECTION_H
#define CARD_GAME_FRAMEWORK_CARDCOLLECTION_H

#include <vector>
#include <string>
#include "Card.h"

class CardCollection {
protected:
    std::vector<Card*> _vCards;
private:
    std::string _collectionType;
public:
    CardCollection(std::string type);
	virtual ~CardCollection();
    void transfer(CardCollection& to, int index);
    void transfer(CardCollection& to, int start, int end);
    void transferAll(CardCollection& to);
    int size();
    Card* getCard(int index);
    Card* top();
    Card* last();
	Card* operator[](int index);
	void removeFromCardCollection(CardCollection& from);
    void removeCard(int index);
    void removeAll();
	void clear();
	int findIndex(Card* card);
    void addCard(Card* card);
	void addCard(int index, Card* card);
	std::string getType();
	Card* popCard();
};

#endif //CARD_GAME_FRAMEWORK_CARDCOLLECTION_H
