//
// Created by Andrew on 2016-04-15.
//

#include <iosfwd>
#include "../include/BigTwoCPUPlayer.h"

BigTwoCPUPlayer::BigTwoCPUPlayer(std::string name) : Player(name) { }

bool BigTwoCPUPlayer::isHuman() {
    return false;
}

std::string BigTwoCPUPlayer::makeSelection(int playLimit, Pile& playPile) {
    return "valid";
}

bool BigTwoCPUPlayer::isPlayable(Hand& selection, Pile& playPile){
    if(playPile.pileSize() != '\0'){
        Hand topHand = playPile.getTopHand();
        if (topHand.size() == 1) {
            // handle singles
            Card *topCard = topHand.top();
            Card *largerCard = getHand().findLargerThan(topCard);

            if(largerCard!= nullptr){
                if ((largerCard->getRank() >= 0) && (largerCard->getSuite() >= 0)) {
                    // make selection
                    getSelection().addCard(largerCard);
                }
            }
        }
    }else{
        // make selection
        Card* smallestCard = getHand().findSmallest();
        getSelection().addCard(smallestCard);
    }
    return true;
}

bool BigTwoCPUPlayer::isValid(Hand& selection) {
    return true;
}

bool BigTwoCPUPlayer::play(Pile &playPile, int handIndex) {
    if(getSelection().size()==0){
        std::cout << "     " << getName() << " passed";
        std::cout << " and has " << (getHand().size()) << " cards left";
        playPile.clearPile();
    }else{
        std::cout << "     " << getName() << " played " << getSelection().toString();
        std::cout << " and has " << (getHand().size()-1) << " cards left";
    }
    std::cout << std::endl << std::endl;
    Player::play(playPile, handIndex);
    return true;
}
