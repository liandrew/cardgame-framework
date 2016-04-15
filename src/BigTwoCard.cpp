//
// Created by Andrew on 2016-04-15.
//

#include "../include/BigTwoCard.h"

BigTwoCard::BigTwoCard(int rank, const Suite suite, bool turned) : Card(rank, suite, turned) {
    _rank = rank;
    _suite = suite;
    _turned = turned;
}

std::string BigTwoCard::getRankStr() {
    return BigTwoCardStrings::getShortRank(_rank);
}

std::string BigTwoCard::getSuiteStr() {
    return BigTwoCardStrings::getShortSuite(_suite);
}

std::string BigTwoCard::toString() {
    return "[" + getRankStr() + "-" + getSuiteStr() + "]";
}

std::string BigTwoCard::toFullString() {
    return BigTwoCardStrings::getRank(_rank) + " of " + BigTwoCardStrings::getSuite(_suite);
}

std::string BigTwoCardStrings::getSuite(Suite suite) {
    switch (suite) {
        case HEARTS: return "Hearts";
        case DIAMONDS: return "Diamonds";
        case SPADES: return "Spades";
        case CLUBS: return "Clubs";
        default: return "Joker";
    }
}

std::string BigTwoCardStrings::getShortSuite(Suite suite) {
    switch (suite) {
        case HEARTS: return "H";
        case DIAMONDS: return "D";
        case SPADES: return "S";
        case CLUBS: return "C";
        default: return "Joker";
    }
}

std::string BigTwoCardStrings::getRank(int rank) {
    std::string num = "JOKER";
    int number = rank;
    std::string _aRank[13] = {"3", "4", "5", "6", "7", "8", "9", "10",
                                    "Jack", "Queen", "King", "Ace", "2"};
    if(number>=0 && number<=12 ){
        num = _aRank[number];
    }
    return num;
}

std::string BigTwoCardStrings::getShortRank(int rank) {
    std::string num = "JOKER";
    int number = rank;
    std::string _aRank[13] = {"3", "4", "5", "6", "7", "8", "9", "10",
                                    "J", "Q", "K", "A", "2"};
    if(number>=0 && number<=12 ){
        num = _aRank[number];
    }
    return num;
}
