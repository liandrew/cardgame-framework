//
// Created by Andrew on 2016-03-23.
//

#include "../include/Player.h"
#include "../include/validateStrategies/BigTwo_Singles.h"

Player::Player(std::string name) : _hand(nullptr), _selection(nullptr) {
    _name = name;
    _hand = new Hand("Hand");
    _selection = new Hand("Play");
}

std::string Player::getName(){
	return _name;
}

bool Player::isHuman(){
	return false;
}

void Player::setPlayable(IValidatePlay& strategy){
    _pValidatePlay = &strategy;
}

bool Player::isPlayable(Hand& selection, Hand& topPile){
	return _pValidatePlay->isPlayable(selection, topPile);
}

bool Player::isValid(Hand& selection) {
    return  _pValidatePlay->isValid(selection);
}

bool Player::makeSelection(int playLimit){
    std::string selection;
    int limit = 1;
    std::cout << getName() << " make your selection: (p=pass, d=done)" << std::endl;
    while ((limit <= playLimit) && (std::cin >> selection) && (selection.compare("d")!=0)){
        if(selection.compare("p")==0){
            return false;
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
            std::cout << "singles strategy" << std::endl;
            setPlayable(singlesStrategy);
            break;
        case 2:
            std::cout << "pairs strategy" << std::endl;
            setPlayable(pairsStrategy);
            break;
        case 3:
            std::cout << "triples strategy" << std::endl;
            setPlayable(triplesStrategy);
            break;
        case 5:
            std::cout << "poker strategy" << std::endl;
            setPlayable(pokerStrategy);
            break;
        default:
            std::cout << "selection is invalid" << std::endl;
            return false;
    }
	return isValid(*_selection);
}

bool Player::play(Pile &playPile) {
    playPile.setTopHand(*_selection);
    // commit play by removing selection from hand
    _hand->removeFromCardCollection(*_selection);
    // clear selection
    _selection->removeAll();
    return false;
}

Hand& Player::getHand() {
	return *_hand;
}

Hand& Player::getSelection() {
	return *_selection;
}

Player::~Player(){
    if (_hand){
        delete _hand;
    }
    if (_selection){
        delete _selection;
    }
}

void Player::clearSelection() {
    _selection->clear();
}
