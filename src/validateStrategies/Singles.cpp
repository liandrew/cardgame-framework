//
// Created by Andrew on 2016-03-24.
//

#include "../../include/ValidateStrategies/Singles.h"

bool Singles::isPlayable(Hand selection, Hand topPile){
    if(isValidMove(selection, topPile)){
        int myRank = selection.getCard(0)->getRank();
        int mySuite = selection.getCard(0)->getSuite();

        int topRank=-1;
        int topSuite=-1;

        if(topPile.size() != '\0'){
            if(topPile.size() > 1){
                return false;
            }
            topRank = topPile.getCard(0)->getRank();
            topSuite = topPile.getCard(0)->getSuite();
        }

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

bool Singles::isValidMove(Hand selection, Hand topPile){
    return ((selection.size() != '\0') && (selection.size()==1));
}
