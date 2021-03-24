#include "world.h"

World::World(const int x_ini, const int y_ini) {
  min_x_ = -x_ini;
  max_x_ = x_ini;
  min_y_ = -y_ini;
  max_y_ = y_ini;
  board_.resize(min_x_, max_x_);
  for (int i = min_x_; i < max_x_; i++) {
    board_.at(i).resize(min_y_, max_y_);
  }

  //Inicializamos el tablero a 0
  for (int i = min_x_; i < max_x_; i++) {
    for (int j = min_y_; j < max_y_; j++) {
      board_.at(i).at(j) = 0;
    }
  }
}

int World::get_cell_colour(const int x, const int y)const {
  return board_.at(x).at(y);
}

void World::change_cell_colour(const int x, const int y) {
  if (board_[x][y] == WHITE) {
    board_[x][y] = BLACK;
  } else if(board_[x][y] == BLACK){
    board_[x][y] = WHITE;
  }
}

void World::print_cell(const int& i, const int& j)const {
  int cell_colour;
  cell_colour = get_cell_colour(i,j);
  switch (cell_colour) {
    case WHITE:
      std::cout << ' ';
      break;
    case BLACK:
      std::cout << 'X';
      break;  
  }
}

void World::print_world(std::vector<Ant*>& ants) {
  int k = 0;
  for (int i = min_x_; i < max_x_; i++) {
    std::cout << "\n";
    for (int j = min_y_; j < max_y_; j++) {
      if ((k < ants.size() && i == ants.at(k)->get_position().x) && (j == ants.at(k)->get_position().y )) {
        ants.at(k)->print_ant();
        k++;
      }else {
        print_cell(i,j);
      }
    }
  }
  std::cout << "\n";
}

void World::check_out_of_bounds(std::vector<Ant*>& ants) {
  for (int i = 0; i < ants.size(); i++) {
    try {
      int test = get_cell_colour(ants[i]->get_position().x, ants[i]->get_position().y);
    } catch(const vector_out_of_bounds_exception& e) {
      handle_out_of_bounds(ants);
    }

  }

}

