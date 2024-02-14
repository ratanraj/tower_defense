#include "monsters.h"
#include "utils.h"
Monster::Monster() {
  x=1024/2;
  y=0;
  health=100;
  alive=true;
  monster_type=B_MONSTER_A;
}

Monster::Monster(int x, int y) {
  this->x=x;
  this->y=y;
  alive=true;
  switch(randint(0, 3)) {
    case 0:
    monster_type=B_MONSTER_A;
    break;
    case 1:
    monster_type=B_MONSTER_B;
    break;
    case 2:
    monster_type=B_MONSTER_C;
    break;
    default:
    monster_type=B_MONSTER_C;
  }
}

Monster::Monster(int x, int y, enum Sprite t) {
  this->x=x;
  this->y=y;
  alive=true;
  monster_type=t;
}

void Monster::move_to(int x, int y) {
  this->x = x;
  this->y = y;
  alive=true;
  monster_type=B_MONSTER_A;
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
      case B_MONSTER_A:
        factor = 1;
        break;
      case B_MONSTER_B:
        factor = 2;
        break;
      case B_MONSTER_C:
        factor = 3;
      case B_MONSTER_Z:
        factor = 4;
      default:
        
        break;
    }
    health = health-factor;
  }
}

int Monster::get_x() {
  return x;
}

int Monster::get_y() {
  return y;
}

bool Monster::is_alive() {
  return alive;
}

void Monster::forward() {
  int factor=1;
  switch (monster_type) {
    case B_MONSTER_A:
      factor=1;
      break;
    case B_MONSTER_B:
      factor=2;
      break;
    case B_MONSTER_C:
      factor=3;
      break;
    case B_MONSTER_Z:
      factor=4;
      break;
  }
  y=y+factor;
}

enum Sprite Monster::get_monster_type() {
  return this->monster_type;
}
