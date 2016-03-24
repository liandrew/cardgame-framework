//
// Created by Andrew on 2016-03-23.
//

#include "../include/Player.h"

Player::Player(std::string name){
    _name = name;
    _hand = new Hand("Hand");
    _selection = new Hand("Play");
}

std::string Player::getName(){

}

bool Player::isHuman(){

}

void Player::setPlayable(IValidatePlay& strategy){

}

bool Player::isPlayable(Hand selection, Hand topPile){

}

void Player::play(Hand selection, Pile playPile){

}

Player::~Player(){
    if (_hand){
        delete _hand;
    }
    if (_selection){
        delete _selection;
    }
}