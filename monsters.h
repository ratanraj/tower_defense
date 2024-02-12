#ifndef _MONSTERS_H
#define _MONSTERS_H

class Monster {
private:
  float x;
  float y;
  float health;
  bool alive;
  char monster_type;
public:
  Monster();

  void move_to(int x, int y);
  float get_health();
  void damage();
  void kill();
};

#endif / _MONSTERS_H
