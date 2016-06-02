//
// Created by Andrew and Jesse on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_CARD_H
#define CARD_GAME_FRAMEWORK_CARD_H

#include <string>

enum Suite { DIAMONDS, CLUBS, HEARTS, SPADES}; // order by least to greatestp

class Card {

public:
  Card(int rank, Suite suite, bool turned = false);
  int getRank();
  Suite getSuite();
  bool getTurned();
  void setTurned(bool turned);
  virtual std::string getRankStr();
  virtual std::string getSuiteStr();
  virtual std::string toString();
  virtual std::string toFullString();
protected:
  int _rank;
  Suite _suite;
  bool _turned;
};

struct CardStrings {
public:
  static std::string getSuite(Suite suite);
  static std::string getShortSuite(Suite suite);
  static std::string getRank(int rank);
  static std::string getShortRank(int rank);
};

#endif //CARD_GAME_FRAMEWORK_CARD_H
