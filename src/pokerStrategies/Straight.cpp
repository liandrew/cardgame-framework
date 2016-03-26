//
// Created by Andrew on 2016-03-24.
//

#include "../../include/PokerStrategies/Straight.h"

bool Straight::isPokerPlayable(Hand selection, Hand topPile){
	//Highest ranking card at the top of the sequence wins
	if((topPile.size() != '\0')
	   && (selection.getCard(0)->getRank() > topPile.getCard(0)->getRank())){
		return true;
	}
}

bool Straight::isValidPokerMove(Hand selection, Hand topPile){
	return false;
}