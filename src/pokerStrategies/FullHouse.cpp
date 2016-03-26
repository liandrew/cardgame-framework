//
// Created by Andrew on 2016-03-24.
//

#include <iostream>
#include "../../include/PokerStrategies/FullHouse.h"

bool FullHouse::isPokerPlayable(Hand selection, Hand topPile){
	// Highest three matching cards wins the pot
	int myHighest=0;
	int pileHighest=0;
	if(selection.getCard(0)->getRank()==selection.getCard(1)->getRank() &&
	   selection.getCard(1)->getRank()==selection.getCard(2)->getRank()){
		myHighest=selection.getCard(0)->getRank();
	}else{
		myHighest=selection.getCard(4)->getRank();
	}
	if(topPile.size() != '\0'){
		if(topPile.getCard(0)->getRank()==topPile.getCard(1)->getRank() &&
		   topPile.getCard(1)->getRank()==topPile.getCard(2)->getRank()){
			pileHighest=topPile.getCard(0)->getRank();
		}else{
			pileHighest=topPile.getCard(4)->getRank();
		}
	}else{
		return true;
	}

	if(myHighest > pileHighest){
		return true;
	}
}

bool FullHouse::isValidPokerMove(Hand selection, Hand topPile) {
	return false;
}
