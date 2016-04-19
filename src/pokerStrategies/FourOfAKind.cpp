//
// Created by Andrew on 2016-03-24.
//

#include "../../include/PokerStrategies/FourOfAKind.h"

bool FourOfAKind::isPokerPlayable(Hand& selection, Pile& playPile){
	Hand topHand = playPile.getTopHand();
	if(topHand.size() == '\0'){
		return true;
	}else if(topHand.size() != 5){
		return false;
	}
	// Highest four of a kind wins
	int myHighest=0;
	int pileHighest=0;
	if(selection.getCard(0)->getRank()==selection.getCard(1)->getRank()){
		myHighest=selection.getCard(0)->getRank();
	}else{
		myHighest=selection.getCard(5)->getRank();
	}

    if(topHand.getCard(0)->getRank()==topHand.getCard(1)->getRank()){
        pileHighest=selection.getCard(0)->getRank();
    }else{
        pileHighest=selection.getCard(5)->getRank();
    }

	if(myHighest > pileHighest){
		return true;
	}
}
