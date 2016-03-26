//
// Created by Andrew on 2016-03-24.
//

#include "../../include/PokerStrategies/StraightFlush.h"

bool StraightFlush::isPokerPlayable(Hand selection, Hand topPile){
	// Highest rank at the top of the sequence wins.
	if((topPile.size() != '\0')
	   && (selection.getCard(0)->getRank() > topPile.getCard(0)->getRank())){
		return true;
	}
	return false;
}

bool StraightFlush::isValidPokerMove(Hand selection, Hand topPile){
	return false;
}