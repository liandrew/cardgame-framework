#include <iosfwd>
#include "../include/BigTwoHumanPlayer.h"

//
// Created by Andrew on 2016-04-14.
//
BigTwoHumanPlayer::BigTwoHumanPlayer(std::string name) : Player(name) { }

bool BigTwoHumanPlayer::isHuman() {
    return true;
}

std::string BigTwoHumanPlayer::makeSelection(int playLimit, Pile& playPile) {
    std::string selection;
    int limit = 1;

    std::cout << std::endl;
    std::cout << "     " << "Your hand: " << getHand().toString() << std::endl;
    std::cout << std::endl;
    std::cout << "Make your selection: ('p' to pass, 'd' for done selection, 'q' to quit game)" << std::endl;

    while ((limit <= playLimit) && (std::cin >> selection) && (selection.compare("d")!=0)){
        if(selection.compare("p")==0){
            return "pass";
        }else if(selection.compare("q")==0){
            return "quit";
        }
        int cardIndex = atoi(selection.c_str());

        if((cardIndex >=0) && (cardIndex < _hand->size())){
            // adds card to players selection
            Card* move = _hand->getCard(cardIndex);
            _selection->addCard(move);
            limit++;
        }
    }

    switch(_selection->size()){
        case 1:
            std::cout << "using singles strategy" << std::endl;
            setPlayable(singlesStrategy);
            break;
        case 2:
            std::cout << "using pairs strategy" << std::endl;
            setPlayable(pairsStrategy);
            break;
        case 3:
            std::cout << "using triples strategy" << std::endl;
            setPlayable(triplesStrategy);
            break;
        case 5:
            std::cout << "using poker strategy" << std::endl;
            setPlayable(pokerStrategy);
            break;
        default:
            setPlayable(singlesStrategy);
            return "invalid";
    }

    return (isValid(*_selection) ? "valid" : "invalid");
}

bool BigTwoHumanPlayer::play(Pile &playPile, int handIndex) {
    return Player::play(playPile, handIndex);
}
