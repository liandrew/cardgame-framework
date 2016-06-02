//
// Created by Andrew on 2016-03-24.
//

#include "../../include/ValidateStrategies/BigTwo_Pairs.h"
#include "../../include/Pile.h"
#include <algorithm>

bool BigTwo_Pairs::isPlayable(Hand& selection, Pile& playPile){
  Hand topHand = playPile.getTopHand();
  if(isValid(selection)){
    if(topHand.size()=='\0'){
      return true;
    }else if(topHand.size() != 2){
      return false;
    }
    int myRank = selection.getCard(0)->getRank();
    int mySuite = selection.getCard(0)->getSuite();
    int mySuite_2 = selection.getCard(1)->getSuite();

    int topRank = topHand.getCard(0)->getRank();
    int topSuite = topHand.getCard(0)->getSuite();
    int topSuite_2 = topHand.getCard(1)->getSuite();

    if(myRank > topRank){
      return true;
    }else if(myRank == topRank){
      if(std::max(mySuite,mySuite_2) > std::max(topSuite, topSuite_2)){
        return true;
      }
    }
  }
  return false;
}

bool BigTwo_Pairs::isValid(Hand& selection){
  if((selection.size() != '\0') && (selection.size()==2)){
    if(selection.getCard(0)->getRank() == selection.getCard(1)->getRank()){
      return true;
    }
  }
  return false;
}
