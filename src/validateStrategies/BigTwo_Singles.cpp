//
// Created by Andrew on 2016-03-24.
//

#include "../../include/ValidateStrategies/BigTwo_Singles.h"

bool BigTwo_Singles::isPlayable(Hand& selection, Pile& topPile){
    Hand topHand = topPile.getTopHand();
    if(isValid(selection)){
        if(topHand.size() == '\0' || topHand.size() == 0){
            return true;
        }else if(topHand.size() != 1){
            return false;
        }

        int myRank = selection.getCard(0)->getRank();
        int mySuite = selection.getCard(0)->getSuite();

        int topRank = topHand.getCard(0)->getRank();
        int topSuite = topHand.getCard(0)->getSuite();

        if(myRank > topRank){
            return true;
        }else if(myRank == topRank){
            if(mySuite > topSuite){
                return true;
            }
        }
    }
    return false;
}

bool BigTwo_Singles::isValid(Hand& selection){
    return ((selection.size() != '\0') && (selection.size()==1));
}
