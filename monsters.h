#ifndef _MONSTERS_H
#define _MONSTERS_H
#include "utils.h"

class Monster {
private:
  float x;
  float y;
  float health;
  bool alive;
  enum Sprite monster_type;
public:
  Monster();
  Monster(int x, int y);
  Monster(int x, int y, enum Sprite t);

  void move_to(int x, int y);
  float get_health();
  void damage();
  void kill();
  int get_x();
  int get_y();
  bool is_alive();
  enum Sprite get_monster_type();
  void forward();

};

#endif // _MONSTERS_H
