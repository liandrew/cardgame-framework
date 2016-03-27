//
// Created by Andrew on 2016-03-24.
//

#include "../../include/PokerStrategies/FourOfAKind.h"

bool FourOfAKind::isPokerPlayable(Hand& selection, Hand& topPile){
	if(topPile.size() == '\0'){
		return true;
	}else if(topPile.size() != 5){
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

    if(topPile.getCard(0)->getRank()==topPile.getCard(1)->getRank()){
        pileHighest=selection.getCard(0)->getRank();
    }else{
        pileHighest=selection.getCard(5)->getRank();
    }

	if(myHighest > pileHighest){
		return true;
	}
}
