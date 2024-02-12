#include "monsters.h"

Monster::Monster() {
  x=1024/2;
  y=0;
  health=100;
  alive=true;
  monster_type='A';
}


void Monster::move_to(int x, int y) {
  this->x = x;
  this->y = y;
}

float Monster::get_health() {
  return health;
}

void Monster::damage() {
  int factor = 1;
  if (health<=0) {
    alive=false;
  } else {
    switch (monster_type) {
      case 'A':
        factor = 30;
        break
      case 'B':
        factor = 15;
        break;
      case 'C':
        factor = 10;
      case 'Z':
        factor = 5;
      default:
        
        break;
    }
    health = health-factor;
  }
}
