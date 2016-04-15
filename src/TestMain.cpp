#include <iostream>

#include "../include/Game.h"
//
// Created by Jesse on 2016-03-23.
//

#include "../include/TestGame.h"
#include "../include/BigTwoGame.h"

using namespace std;

int main(int argc, char** argv) {
//  TestGame testing;
  BigTwoGame testing;
  testing.createGame();
  testing.gameLoop();

  system("pause");

  return 0;
}