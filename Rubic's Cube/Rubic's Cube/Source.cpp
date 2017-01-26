#include <iostream>
#include "cube.h"

int main(int argc, char* argv[]) {
  Cube mycube;
  mycube.draw_cube();
  for (; mycube.trackback.size(); mycube.undo_last_step());
  cout << mycube.is_ready();
  return 0;
}  
