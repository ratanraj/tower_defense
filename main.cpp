#include <iostream>
#include <cstdlib>
#include "game.h"

int main() {
  srand((unsigned)time(NULL));
  Game game;

  game.run();
}
