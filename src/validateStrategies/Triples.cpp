//
// Created by Andrew on 2016-03-24.
//

#include "../../include/ValidateStrategies/Triples.h"

bool Triples::isPlayable(Hand selection, Hand topPile){
	if(isValidMove(selection, topPile)) {
		int myRank = selection.getCard(0)->getRank();

		int topRank=-1;

		if(topPile.size()!='\0'){
			if(topPile.size() > 3){
				return false;
			}
			topRank = topPile.getCard(0)->getRank();
		}

		if (myRank > topRank) {
			return true;
		}
	}
	return false;
}

bool Triples::isValidMove(Hand selection, Hand topPile){
	if((selection.size() != '\0') && (selection.size()==3)){
		if((selection.getCard(0)->getRank() == selection.getCard(1)->getRank())
		   && selection.getCard(1)->getRank() == selection.getCard(2)->getRank()){
			return true;
		}
	}
	return false;
}