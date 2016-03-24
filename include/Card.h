//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_CARD_H
#define CARD_GAME_FRAMEWORK_CARD_H

#include <string>

class Card {

public:
    Card(int rank, int suite);
    int getRankIndex();
    int getSuiteIndex();
    std::string toString();
private:
    int _rank;
    int _suite;
};

#endif //CARD_GAME_FRAMEWORK_CARD_H
