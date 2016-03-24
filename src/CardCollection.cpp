//
// Created by Andrew on 2016-03-23.
//

#include "../include/CardCollection.h"
#include "../include/Card.h"

CardCollection::CardCollection(std::string type){
    _collectionType = type;
}

void CardCollection::transfer(CardCollection to, CardCollection from, int index){

}

void CardCollection::transfer(CardCollection to, CardCollection from, int start, int end){

}

void CardCollection::transferAll(CardCollection to, CardCollection from){

}

int CardCollection::size(){

}

Card CardCollection::getCard(int index){

}

Card CardCollection::top(){

}

Card CardCollection::last(){

}

void CardCollection::removeCard(int index){

}

void CardCollection::removeAll(){

}

void CardCollection::addCard(Card card){

}