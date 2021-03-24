class Ant;
#ifndef Ant_H_
#define Ant_H_
#include "world.h"

enum Colour { WHITE, BLACK};

struct Position {
  int x;
  int y;
};

enum Orientation { NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST , NORTH_WEST};

class Ant {
 public:
  Ant(void);
  Ant(const int& rows, const int& cols);
  Position get_position(void);
  int get_orientation(void);
  void set_orientation(const int& orientation);
  void set_position_x(const int& x);
  void set_position_y(const int& y);
  void print_ant(void);
  virtual void update(World* world);
 protected:
  virtual void change_orientation(const int& current_cell_colour) = 0;
  virtual void move_forward() = 0;
  Position position_;
  int orientation_;
};


#endif //Ant_H_