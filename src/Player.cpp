//
// Created by Andrew on 2016-03-23.
//

#include "../include/Player.h"
#include "../include/validateStrategies/BigTwo_Singles.h"

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
  _pValidatePlay = &strategy;
}

bool Player::isPlayable(Hand& selection, Pile& playPile){
  return _pValidatePlay->isPlayable(selection, playPile);
}

bool Player::isValid(Hand& selection) {
  return  _pValidatePlay->isValid(selection);
}

bool Player::play(Pile &playPile, int handIndex) {
  playPile.setTopHand(*_selection);
  // commit play by removing selection from hand
  _hand->removeFromCardCollection(*_selection);
  _selection->removeAll();
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

void Player::clearSelection() {
  _selection->clear();
}
