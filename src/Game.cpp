//
// Created by Andrew on 2016-03-24.
//

#include "../include/Game.h"

Game::Game(std::string name){
    _deck = new Deck("Deck");
    _name = name;
}

void Game::createGame() {
    createPlayers();
    shuffleDeck();
    dealCards();
}

void Game::createPlayers(){

}

void Game::shuffleDeck(){
    _deck->shuffle();
}

void Game::setMaxCardsPerPlay(int playLimit){
    _playLimit = playLimit;
}

int Game::getMaxCardsPerPlay(){
    return _playLimit;
}

void Game::setHandLimit(int handLimit){
    _handLimit = handLimit;
}

int Game::getHandLimit(){
    return _handLimit;
}

void Game::setMaxPlayers(int limit){
    _maxPlayers = limit;
}

int Game::getMaxPlayers(){
    return _maxPlayers;
}

void Game::setNumberOfCPUPlayers(int num){
    _CPUPlayers = num;
}

int Game::getNumberOfCPUPlayers(){
    return _CPUPlayers;
}

void Game::setDescription(std::string description) {
    _description = description;
}

void Game::setName(std::string name){
    _name = name;
}

std::string Game::getName(){
    return _name;
}

std::string Game::getDescription() {
    return _description;
}
