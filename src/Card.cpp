//
// Created by Andrew and Jesse on 2016-03-24.
//

#include "../include/Card.h"
#include "../include/Utility.h"

Card::Card(int rank, Suite suite, bool turned){
  _rank = rank;
  _suite = suite;
  _turned = turned;
}

int Card::getRank() {
  return _rank;
}

Suite Card::getSuite() {
  return _suite;
}

bool Card::getTurned() {
  return _turned;
}

void Card::setTurned(bool turned) {
  _turned = turned;
}

bool operator< (Card &leftCard, Card &rightCard){
  return leftCard.getRank() < rightCard.getRank();
}

bool operator<= (Card &leftCard, Card &rightCard){
  if(leftCard.getRank() < rightCard.getRank()){
    return true;
  }else if(equalTo(leftCard, rightCard)){
    return true;
  }
  return false;
}

bool operator> (Card &leftCard, Card &rightCard){
  return leftCard.getRank() > rightCard.getRank();
}

bool operator>= (Card &leftCard, Card &rightCard){
  if(leftCard.getRank() > rightCard.getRank()){
    return true;
  }else if(equalTo(leftCard, rightCard) ){
    return true;
  }
  return false;
}

bool operator== (Card &leftCard, Card &rightCard){
  return equalTo(leftCard, rightCard);
}

bool equalTo(Card &leftCard, Card &rightCard){
  return (leftCard.getRank() == rightCard.getRank() &&
          leftCard.getSuite() == rightCard.getSuite());
}

std::string Card::getRankStr() {
  return CardStrings::getShortRank(_rank);
}

std::string Card::getSuiteStr() {
  return CardStrings::getShortSuite(_suite);
}

std::string Card::toString() {
  return "[" + getRankStr() + "-" + getSuiteStr() + "]";
}

std::string Card::toFullString() {
  return CardStrings::getRank(_rank) + " of " + CardStrings::getSuite(_suite);
}

std::string CardStrings::getSuite(Suite suite) {
  switch (suite) {
    case HEARTS: return "Hearts";
    case DIAMONDS: return "Diamonds";
    case SPADES: return "Spades";
    case CLUBS: return "Clubs";
    default: return "Joker";
  }
}

std::string CardStrings::getShortSuite(Suite suite) {
  switch (suite) {
  case HEARTS: return "H";
  case DIAMONDS: return "D";
  case SPADES: return "S";
  case CLUBS: return "C";
  default: return "Joker";
  }
}

std::string CardStrings::getRank(int rank) {
  std::string num = "JOKER";
  int number = rank;
  if (number == 1) {
    num = "Ace";
  } else if (number < 11) {
    num = Utility::toString(number);
  } else if (number == 11) {
    num = "Jack";
  } else if (number == 12) {
    num = "Queen";
  } else if (number == 13) {
    num = "King";
  }
  return num;
}

std::string CardStrings::getShortRank(int rank) {
  std::string num = "JOKER";
  int number = rank;
  if (number == 1) {
    num = "A";
  } else if (number < 11) {
    num = Utility::toString(number);
  } else if (number == 11) {
    num = "J";
  } else if (number == 12) {
    num = "Q";
  } else if (number == 13) {
    num = "K";
  }
  return num;
}
