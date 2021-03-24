#include "ant.h"
#include <iostream>

Ant::Ant(void) {
  position_.x = 0;
  position_.y = 0;
  orientation_ = EAST;
}

Ant::Ant(const int& rows, const int& cols) {
  position_.x = rows/2;
  position_.y = cols/2;
  orientation_ = EAST;
}

Position Ant::get_position() {
  return position_;
}

int Ant::get_orientation(void) {
  return orientation_;
}

void Ant::set_position_x(const int& x) {
  position_.x = x;
}

void Ant::set_position_y(const int& y){
  position_.y = y;
}

void Ant::set_orientation(const int& orientation) {
  orientation_ = orientation;
}

void Ant::print_ant(void) {
  switch (orientation_) {
    case NORTH:
      std::cout << '^';
      break;
    case NORTH_EAST:
      std::cout << '/';
      break;
      case EAST:
      std::cout << '>';
      break;
    case SOUTH_EAST:
      std::cout << ';';
      break;
    case SOUTH:
      std::cout << 'v';
      break;
    case SOUTH_WEST:
      std::cout << ',';
      break;
      case WEST:
      std::cout << '<';
      break;
    case NORTH_WEST:
      std::cout << '`';
      break;   
  }
}

void Ant::update(World* world) {
  change_orientation(world->get_cell_colour(position_.x, position_.y));
  world->change_cell_colour(position_.x, position_.y);
  move_forward();
}