#ifndef _TOWER_H
#define _TOWER_H

class Tower {
  private:
    int x;
    int y;
    int range;
  public:
    Tower();

    int get_x();
    int get_y();
    int get_range();

    // is_within_range returns true if the distance from 
    // point specified with (x,y) is less than range
    bool is_within_range(int x, int y); 
};

#endif // !_TOWER_H
