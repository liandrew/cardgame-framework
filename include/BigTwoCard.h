//
// Created by Andrew on 2016-04-14.
//

#ifndef CARD_GAME_FRAMEWORK_BIGTWOCARD_H
#define CARD_GAME_FRAMEWORK_BIGTWOCARD_H

#include "Card.h"

class BigTwoCard : public Card {
public:
    BigTwoCard(int rank, Suite suite, bool turned = false);
    std::string getRankStr();
    std::string getSuiteStr();
    std::string toString();
    std::string toFullString();
};

struct BigTwoCardStrings {
public:
    static std::string getSuite(Suite suite);
    static std::string getShortSuite(Suite suite);
    static std::string getRank(int rank);
    static std::string getShortRank(int rank);
};

#endif //CARD_GAME_FRAMEWORK_BIGTWOCARD_H
