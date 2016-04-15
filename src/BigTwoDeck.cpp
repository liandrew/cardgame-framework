//
// Created by Andrew on 2016-04-15.
//

#include "../include/BigTwoDeck.h"
#include "../include/BigTwoCard.h"

BigTwoDeck::BigTwoDeck(const std::string &type) : Deck(type) {
    makeDeck();
}

void BigTwoDeck::makeDeck() {
    for(int suite=0; suite<= 3; suite++){
        for(int rank=0; rank<=12; rank++){
            addCard(new BigTwoCard(rank,(Suite)suite));
        }
    }
    _vOriginal = _vCards;
}
