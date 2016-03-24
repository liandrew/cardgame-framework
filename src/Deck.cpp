//
// Created by Andrew on 2016-03-24.
//

#include <string>
#include "../include/CardCollection.h"
#include "../include/Card.h"
#include "../include/Deck.h"

Deck::Deck(const std::string &type) : CardCollection(type){
    for(int suite=0; suite<= 3; suite++){
        for(int rank=0; rank<=12; rank++){
            CardCollection::addCard(Card(rank,suite));
        }
    }
}

void Deck::deal(CardCollection &hand, int handSize){

}

void Deck::shuffle(){

}