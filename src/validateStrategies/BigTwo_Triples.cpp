//
// Created by Andrew on 2016-03-24.
//

#include "../../include/ValidateStrategies/BigTwo_Triples.h"

bool BigTwo_Triples::isPlayable(Hand& selection, Hand& topPile){
	if(isValid(selection)) {
		if(topPile.size()=='\0'){
			return true;
		}else if(topPile.size() != 3){
			return false;
		}

		int myRank = selection.getCard(0)->getRank();
        int topRank = topPile.getCard(0)->getRank();

		if (myRank > topRank) {
			return true;
		}
	}
	return false;
}

bool BigTwo_Triples::isValid(Hand& selection){
	if((selection.size() != '\0') && (selection.size()==3)){
		if((selection.getCard(0)->getRank() == selection.getCard(1)->getRank())
		   && selection.getCard(1)->getRank() == selection.getCard(2)->getRank()){
			return true;
		}
	}
	return false;
}