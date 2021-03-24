#include "inverse_langton_ant.h"

void Inverse_langton_ant::change_orientation(const int& current_cell_colour) {
 switch (orientation_) {
    case NORTH:
      if(current_cell_colour == WHITE) {
        orientation_ = NORTH_EAST;
      } else if(current_cell_colour == BLACK){
        orientation_ = NORTH_WEST;
      }
      break;
    case NORTH_EAST:
      if(current_cell_colour == WHITE) {
        orientation_ = EAST;
      } else if(current_cell_colour == BLACK){
        orientation_ = NORTH;
      }
      break;
    case EAST:
      if(current_cell_colour == WHITE) {
        orientation_ = SOUTH_EAST;
      } else if(current_cell_colour == BLACK){
        orientation_ = NORTH_EAST;
      }
      break;
    case SOUTH_EAST:
      if(current_cell_colour == WHITE) {
        orientation_ = SOUTH;
      } else if(current_cell_colour == BLACK){
        orientation_ = EAST;
      }
      break;
    case SOUTH:
      if(current_cell_colour == WHITE) {
        orientation_ = SOUTH_WEST;
      } else if(current_cell_colour == BLACK){
        orientation_ = SOUTH_EAST;
      }
      break;
    case SOUTH_WEST:
      if(current_cell_colour == WHITE) {
        orientation_ = WEST;
      } else if(current_cell_colour == BLACK){
        orientation_ = SOUTH_WEST;
      }
      break;
    case WEST:
      if(current_cell_colour == WHITE) {
        orientation_ = NORTH_WEST;
      } else if(current_cell_colour == BLACK){
        orientation_ = SOUTH_WEST;
      }
      break;
    case NORTH_WEST:
      if(current_cell_colour == WHITE) {
        orientation_ = NORTH;
      } else if(current_cell_colour == BLACK){
        orientation_ = NORTH_WEST;
      }
      break;  
  }
}

void Inverse_langton_ant::move_forward() {
  switch (orientation_) {
    case NORTH:
      position_.x += -1;
      break;
    case NORTH_EAST:
      position_.x += -1;
      position_.y += 1;
      break;
    case EAST:
      position_.y += 1;
      break;
    case SOUTH_EAST:
      position_.x += 1;
      position_.y += 1;
      break;  
    case SOUTH:
      position_.x += 1;
      break;
    case SOUTH_WEST:
      position_.y += -1;
      position_.x += 1;
      break;
    case WEST:
      position_.y += -1;
      break;
    case NORTH_WEST:
      position_.y += -1;
      position_.x += -1;
      break;  
  }
}