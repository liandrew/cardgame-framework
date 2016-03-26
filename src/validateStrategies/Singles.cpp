//
// Created by Andrew on 2016-03-24.
//

#include "../../include/ValidateStrategies/Singles.h"

bool Singles::isPlayable(Hand selection, Hand topPile){
    if(isValid(selection)){
        if(topPile.size() == '\0'){
            return true;
        }else if(topPile.size() != 1){
            return false;
        }

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
    }
    return false;
}

bool Singles::isValid(Hand selection){
    return ((selection.size() != '\0') && (selection.size()==1));
}
