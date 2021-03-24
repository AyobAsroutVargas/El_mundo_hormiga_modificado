#include<exception>

class vector_out_of_bounds_exception : public std::exception {
 public:
  virtual const char* what(void) const throw () {
    return "Tried to access a position outside the vector\n";
  }
};


