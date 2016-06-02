//
// Created by Andrew on 2016-03-24.
//

#include "../../include/PokerStrategies/Straight.h"

bool Straight::isPokerPlayable(Hand& selection, Pile& playPile){
  Hand topHand = playPile.getTopHand();
  if(topHand.size() == '\0'){
    return true;
  }else if(topHand.size() != 5){
    return false;
  }
  //Highest ranking card at the top of the sequence wins
  if((selection.getCard(0)->getRank() > topHand.getCard(0)->getRank())){
    return true;
  }
}
