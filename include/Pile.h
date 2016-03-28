//
// Created by Andrew on 2016-03-24.
//

#ifndef CARD_GAME_FRAMEWORK_PILE_H
#define CARD_GAME_FRAMEWORK_PILE_H

#include<string>
#include "Hand.h"

class Pile {
private:
    std::vector<Hand> _vPile;
    std::string _type;
public:
    Pile(const std::string &type);
    void setPile(std::vector<Hand> vPile);
    std::vector<Hand> getPile();
    Hand& getTopHand();
    Hand& get(int i);
    Hand& operator[](int i);
    void setTopHand(Hand play);
    void clearPile();
    int pileSize();
    std::string toString();
};

#endif //CARD_GAME_FRAMEWORK_PILE_H
