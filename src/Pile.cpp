//
// Created by Andrew on 2016-03-24.
//

#include<string>
#include "../include/Pile.h"

Pile::Pile(const std::string &type){
    _type = type;
}

void Pile::setPile(std::vector<Hand> vPile){
	_vPile = vPile;
}

std::vector<Hand> Pile::getPile(){
	return _vPile;
}

Hand Pile::getTopHand(){
	return _vPile.back();
}

void Pile::setTopHand(Hand play){
	_vPile.push_back(play);
}

void Pile::clearPile(){
	_vPile.clear();
}

int Pile::pileSize(){
	return _vPile.size();
}

std::string Pile::toString(){
	std::string result = "";
	std::vector<Hand>::iterator it = Pile::_vPile.begin();
	for(; it != Pile::_vPile.end(); ++it) {
		result = result + (*it).toString();
	}
	return result;
}