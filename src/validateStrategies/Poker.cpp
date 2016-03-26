//
// Created by Andrew on 2016-03-24.
//

#include <map>
#include <iostream>
#include "../../include/ValidateStrategies/Poker.h"

void Poker::setPokerPlayable(IPokerValidatePlay &strategy) {
	_pValidatePokerPlay = &strategy;
}

bool Poker::isPokerPlayable(Hand selection, Hand topPile){
	return _pValidatePokerPlay->isPokerPlayable(selection, topPile);
}

PokerHand Poker::isPokerValid(Hand selection){
	if(selection.size()!='\0' && selection.size()==5){
		// start analyzing
		bool isHandOrdered = true;
		bool areSuitesAllSame = true;

		int orderTrack = 0;
		int suiteTrack = 0;
		std::map<int,int> matchingRankList;

		selection.sort();

		for(int i=0; i<selection.size();i++){
			int rankIndex = selection.getCard(i)->getRank();
			int suiteIndex = selection.getCard(i)->getSuite();

			try{
				int value = matchingRankList.at(rankIndex);
				matchingRankList[rankIndex] = ++value;
			}catch (std::out_of_range e){
				matchingRankList[rankIndex] = 1;
			}

			if(orderTrack==0){
				orderTrack = rankIndex;
				suiteTrack = suiteIndex;
			}else {
				if (orderTrack != rankIndex) {
					isHandOrdered = false;
				}
				if (suiteTrack != suiteIndex){
					areSuitesAllSame = false;
				}
			}
			orderTrack++;
		}

		int largest=0;
		int value=0;

		std::map<int,int>::iterator mIt = matchingRankList.begin();
		for(; mIt != matchingRankList.end(); ++mIt){
			value = (*mIt).second;
			if(value>largest){
				largest = value;
			}
		}

		if(largest==4){
			return FOUROFAKIND;
		}else if(largest==3){
			return FULLHOUSE;
		}

		if(isHandOrdered){
			if(areSuitesAllSame){
				return STRAIGHTFLUSH;
			}else{
				return STRAIGHT;
			}
		}else if((!isHandOrdered && areSuitesAllSame)){
			return FLUSH;
		}
	}
	return INVALID;
}

bool Poker::isPlayable(Hand selection, Hand topPile){
	bool result = false;
	PokerHand myPokerValue;
	PokerHand pilePokerValue;

	myPokerValue = isPokerValid(selection);
	pilePokerValue = isPokerValid(topPile);

	std::cout << "My poker value = " << myPokerValue << std::endl;
	std::cout << "My pile poker value = " << pilePokerValue << std::endl;

	if(myPokerValue > pilePokerValue){
		return true;
	}else if(myPokerValue == pilePokerValue){
		switch (myPokerValue) {
			case STRAIGHTFLUSH:
				std::cout << "straight flush" << std::endl;
				setPokerPlayable(_straightFlushStrategy);
				break;
			case FOUROFAKIND:
				std::cout << "four of a kind" << std::endl;
				setPokerPlayable(_fourOfAKindStrategy);
				break;
			case FULLHOUSE:
				std::cout << "full house" << std::endl;
				setPokerPlayable(_fullhouseStrategy);
				break;
			case FLUSH:
				std::cout << "flush" << std::endl;
				setPokerPlayable(_straightFlushStrategy);
				break;
			case STRAIGHT:
				std::cout << "straight flush" << std::endl;
				setPokerPlayable(_straightStrategy);
				break;
		}
		result = isPokerPlayable(selection,topPile);
	}
	return result;
}

bool Poker::isValid(Hand selection){
	return (isPokerValid(selection) != INVALID);
}
