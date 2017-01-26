#include <iostream>
#include "cube.h"
#include "Solver.h"

int main(int argc, char* argv[]) {
  Cube mycube;
  mycube.draw_cube();
  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
  Solver solver(&mycube);
  mycube.draw_cube();
  return 0;
}  
