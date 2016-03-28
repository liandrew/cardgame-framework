//
// Created by Andrew on 2016-03-24.
//

#include "../../include/ValidateStrategies/Pairs.h"
#include <algorithm>

bool Pairs::isPlayable(Hand selection, Hand topPile){
	if(isValid(selection)){
		if(topPile.size()=='\0'){
			return true;
		}else if(topPile.size() != 2){
			return false;
		}
		int myRank = selection.getCard(0)->getRank();
		int mySuite = selection.getCard(0)->getSuite();
		int mySuite_2 = selection.getCard(1)->getSuite();

        int topRank = topPile.getCard(0)->getRank();
        int topSuite = topPile.getCard(0)->getSuite();
        int topSuite_2 = topPile.getCard(1)->getSuite();

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

bool Pairs::isValid(Hand selection){
	if((selection.size() != '\0') && (selection.size()==2)){
		if(selection.getCard(0)->getRank() == selection.getCard(1)->getRank()){
			return true;
		}
	}
	return false;
}
