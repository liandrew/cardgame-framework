//
// Created by Andrew on 2016-03-24.
//

#include "../include/Game.h"

Game::Game(std::string name){
    _deck = new Deck("Deck");
    _name = name;
	_isActive = true;
	_playerTurn = 0;
	_gameTurn = 0;
}

void Game::createGame() {
    createPlayers();
    shuffleDeck();
    dealCards();
}

void Game::shuffleDeck(){
    _deck->shuffle();
}

bool Game::isActive() {
	return _isActive;
}

void Game::setActive(bool active) {
	_isActive = active;
}

void Game::gameLoop() {
	while (_isActive && _vPlayers.size()) {
		_gameTurn++;
		_playerTurn = _gameTurn % _vPlayers.size();
		playerAction(*_vPlayers[_playerTurn]);
	}
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

Player& Game::getCurrentPlayer() {
	return *_vPlayers[_gameTurn % _vPlayers.size()];
}

int Game::getTurn() {
	return _vPlayers.size() ? _gameTurn / _vPlayers.size() : 0;
}
