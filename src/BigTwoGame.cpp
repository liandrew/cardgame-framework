//
// Created by Andrew on 2016-04-15.
//

#include <iosfwd>
#include <sstream>
#include "../include/BigTwoGame.h"
#include "../include/BigTwoParts.h"
#include "../include/BigTwoDeck.h"

BigTwoGame::BigTwoGame() : Game("Big Two Game") {
    _factory = new BigTwoParts();
    _deck = _factory->makeDeck();
    _pile = _factory->makePile();

    _winningPlayer = nullptr;
}

void BigTwoGame::gameLoop() {
    Game::gameLoop();
}

Player &BigTwoGame::getCurrentPlayer() {
    return Game::getCurrentPlayer();
}

void BigTwoGame::playerAction(Player &player) {
    std::cout << "It's " << player.getName() << "'s Turn!" << std::endl;
    player.getHand().sort();

    bool isPlayable;
    std::string selectedOption;

    do{
        std::cout << std::endl << "     Play Pile: " << _pile->toString() << std::endl;
        selectedOption = player.makeSelection(getMaxCardsPerPlay(), *_pile);
        std::cout << std::endl;

        if(selectedOption == "pass"){
            _pile->clearPile();
            break;
        }else if(selectedOption == "quit"){
            _isActive = false;
            break;
        }

        isPlayable = player.isPlayable(player.getSelection(), *_pile);

        if(isPlayable){
          player.play(*_pile);
          isWinner(player);
        }else{
          std::cout << std::endl << player.getName();
          std::cout << " Your move was invalid, try another selection" << std::endl;
          player.clearSelection();
        }

    }while(!isPlayable);
}

void BigTwoGame::setRules() {
    setMaxCardsPerPlay(5);
    setHandLimit(13);
    setMaxPlayers(4);
}

void BigTwoGame::createPlayers() {
    _vPlayers.push_back(_factory->makePlayer("Human"));
    for(int i=1; i<=3;i++){
        std::stringstream ss;
        ss << "CPU " << (i);
        _vPlayers.push_back(_factory->makeCPUPlayer(ss.str()));
    }
}

void BigTwoGame::dealCards() {
    for(int i=0; i < _vPlayers.size(); i++){
        _deck->deal(_vPlayers[i]->getHand(), getHandLimit());
    }
}

bool BigTwoGame::isWinner(Player &player) {
    if(player.getHand().size() == 0){
        _winningPlayer = &player;
        setWinCondition();
        return true;
    }
    return false;
}

void BigTwoGame::setWinCondition() {
    if (_winningPlayer) {
        setActive(false);
        std::cout << _winningPlayer->getName() << " wins!" << std::endl;
    }
}

BigTwoGame::~BigTwoGame() {
    if (_pile) {
        delete _pile;
    }
    if (_factory) {
        delete _factory;
    }
}