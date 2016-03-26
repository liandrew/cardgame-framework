//
// Created by Andrew on 2016-03-24.
//

#include "../../include/ValidateStrategies/Pairs.h"

bool Pairs::isPlayable(Hand selection, Hand topPile){
	if(isValidMove(selection, topPile)){
		int myRank = selection.getCard(0)->getRank();
		int mySuite = selection.getCard(0)->getSuite();
		int mySuite_2 = selection.getCard(1)->getSuite();

		int topRank=-1;
		int topSuite=-1;
		int topSuite_2=-1;

		if(topPile.size()!='\0'){
			if(topPile.size() > 2){
				return false;
			}
			topRank = topPile.getCard(0)->getRank();
			topSuite = topPile.getCard(0)->getSuite();
			topSuite_2 = topPile.getCard(1)->getSuite();
		}

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

bool Pairs::isValidMove(Hand selection, Hand topPile){
	if((selection.size() != '\0') && (selection.size()==2)){
		if(selection.getCard(0)->getRank() == selection.getCard(1)->getRank()){
			return true;
		}
	}
	return false;
}
