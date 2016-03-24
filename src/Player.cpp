//
// Created by Andrew on 2016-03-23.
//

#include "../include/Player.h"

Player::Player(std::string name) : _hand(nullptr), _selection(nullptr) {
    _name = name;
    _hand = new Hand("Hand");
    _selection = new Hand("Play");
}

std::string Player::getName(){
	return _name;
}

bool Player::isHuman(){
	return false;
}

void Player::setPlayable(IValidatePlay& strategy){

}

bool Player::isPlayable(Hand selection, Hand topPile){
	return false;
}

bool Player::play(Hand selection, Hand playPile){
	return false;
}

Hand& Player::getHand() {
	return *_hand;
}

Hand& Player::getSelection() {
	return *_selection;
}

Player::~Player(){
    if (_hand){
        delete _hand;
    }
    if (_selection){
        delete _selection;
    }
}