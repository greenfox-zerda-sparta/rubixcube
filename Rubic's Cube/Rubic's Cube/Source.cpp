#include <iostream>
#include "cube.h"

int main(int argc, char* argv[]) {
  Cube mycube;
  /*
  cout << "FRONT ROTATION" << endl;
  mycube.rotate_front();
  mycube.rotate_front();
  mycube.rotate_front();
  mycube.rotate_front();
  */
  mycube.draw_cube();
  cout << "Is it ready? " << mycube.is_ready() << endl;


  cout << "Rotated left." << endl;
  mycube.rotate_left();
  cout << "Is it ready? " << mycube.is_ready() << endl;

  cout << "Rotated left 3 times." << endl;
  mycube.rotate_left();
  mycube.rotate_left();
  mycube.rotate_left();
  cout << "Is it ready? " << mycube.is_ready() << endl;
  /*
  cout << "UP ROTATION" << endl;
  mycube.rotate_up();
  mycube.draw_cube();

  cout << "Back ROTATION" << endl;
  mycube.rotate_back();
  mycube.draw_cube();
  
  cout << "Down ROTATION" << endl;
  mycube.rotate_down();
  mycube.draw_cube();
  
  cout << "Left ROTATION" << endl;
  mycube.roatate_left();
  mycube.draw_cube();
  
  cout << "Right ROTATION" << endl;
  mycube.rotate_right
  mycube.draw_cube();*/
  
  
  return 0;
}  
