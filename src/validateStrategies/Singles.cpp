//
// Created by Andrew on 2016-03-24.
//

#include "../../include/ValidateStrategies/Singles.h"

bool Singles::isPlayable(Hand selection, Hand topPile){
    int myRank = selection.getCard(0)->getRank();
    int mySuite = selection.getCard(0)->getSuite();

    int topRank = topPile.getCard(0)->getRank();
    int topSuite = topPile.getCard(0)->getSuite();

    if(myRank > topRank){
        return true;
    }else if(myRank == topRank){
        if(mySuite > topSuite){
            return true;
        }
    }
    return false;
}

bool Singles::isValidMove(Hand selection, Hand topPile){
    bool result = false;
    if(selection.size()==1){
        result = true;
    }
    return result;
}
