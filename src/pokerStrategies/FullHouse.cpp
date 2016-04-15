//
// Created by Andrew on 2016-03-24.
//

#include <iostream>
#include "../../include/PokerStrategies/FullHouse.h"

bool FullHouse::isPokerPlayable(Hand& selection, Pile& playPile){
	Hand topHand = playPile.getTopHand();
	if(topHand.size() == '\0'){
		return true;
	}else if(topHand.size() != 5){
		return false;
	}
	// Highest three matching cards wins the pot
	int myHighest=0;
	int pileHighest=0;

	if(selection.getCard(0)->getRank()==selection.getCard(1)->getRank() &&
	   selection.getCard(1)->getRank()==selection.getCard(2)->getRank()){
		myHighest=selection.getCard(0)->getRank();
	}else{
		myHighest=selection.getCard(4)->getRank();
	}

    if(topHand.getCard(0)->getRank()==topHand.getCard(1)->getRank() &&
            topHand.getCard(1)->getRank()==topHand.getCard(2)->getRank()){
        pileHighest=topHand.getCard(0)->getRank();
    }else{
        pileHighest=topHand.getCard(4)->getRank();
    }

	return (myHighest > pileHighest);
}
