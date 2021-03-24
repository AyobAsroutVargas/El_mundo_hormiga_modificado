#ifndef Inverse_langton_ant_H_
#define Inverse_langton_ant_H_

#include "ant.h"

class Inverse_langton_ant : public Ant {
 public:
  Inverse_langton_ant(const int& rows, const int& cols):Ant(rows,cols){}
  Inverse_langton_ant(void):Ant(){}
 private:
  void change_orientation(const int& current_cell_colour);
  void move_forward();
};

#endif //Inverse_langton_ant_H_