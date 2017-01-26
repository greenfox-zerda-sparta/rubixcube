#include <iostream>
#include "cube.h"

int main(int argc, char* argv[]) {
  Cube mycube;
  
  mycube.rotate_front();
  mycube.roatate_left();
  mycube.rotate_down();

  mycube.draw_cube();
  
  
  return 0;
}  
