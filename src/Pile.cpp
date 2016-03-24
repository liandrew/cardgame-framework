//
// Created by Andrew on 2016-03-24.
//

#include<string>
#include "../include/Pile.h"

Pile::Pile(const std::string &type){
    _type = type;
}

void Pile::setPile(std::vector<Hand> vPile){

}

std::vector<Hand> Pile::getPile(){
	return std::vector<Hand>();
}

Hand Pile::getTopHand(){
	return _vPile[_vPile.size() - 1];
}

void Pile::setTopHand(Hand play){
	_vPile.push_back(play);
}

void Pile::clearPile(){

}

int Pile::pileSize(){
	return _vPile.size();
}

std::string Pile::toString(){
	return _type;
}