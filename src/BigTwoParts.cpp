//
// Created by Andrew on 2016-04-14.
//


#include "../include/BigTwoParts.h"
#include "../include/BigTwoHumanPlayer.h"
#include "../include/BigTwoCPUPlayer.h"

Player* BigTwoParts::makePlayer(std::string name){
    return new BigTwoHumanPlayer(name);
}

Player* BigTwoParts::makeCPUPlayer(std::string name){
    return new BigTwoCPUPlayer(name);
}

BigTwoPile* BigTwoParts::makePile(){
    return new BigTwoPile("Pile");
}

BigTwoDeck* BigTwoParts::makeDeck() {
    return new BigTwoDeck("Deck");
}

BigTwoParts::~BigTwoParts() {
}
