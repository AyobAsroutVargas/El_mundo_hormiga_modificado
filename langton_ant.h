#ifndef Langton_ant_H_
#define Langton_ant_H_

#include "ant.h"

class Langton_ant : public Ant {
 public:
  Langton_ant(const int& rows, const int& cols):Ant(rows,cols){}
  Langton_ant(void):Ant(){}
 private:
  void change_orientation(const int& current_cell_colour);
  void move_forward();
};

#endif //Langton_ant_H_