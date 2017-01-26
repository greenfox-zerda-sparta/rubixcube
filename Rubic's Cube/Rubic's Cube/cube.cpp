#include "Cube.h"

Cube::Cube() {
  faces_of_cube.push_back(front);
  faces_of_cube.push_back(up);
  faces_of_cube.push_back(back);
  faces_of_cube.push_back(down);
  faces_of_cube.push_back(right);
  faces_of_cube.push_back(left);
}

void Cube::rotate_front() {
  char temp = front[0];
  front[0] = front[6];
  front[6] = front[8];
  front[8] = front[2];
  front[2] = temp;
  temp = front[1];
  front[1] = front[3];
  front[3] = front[7];
  front[7] = front[5];
  front[5] = temp;
 
  char temp0 = up[6];
  char temp1 = up[7];
  char temp2 = up[8];
  up[6] = left[8];
  up[7] = left[5];
  up[8] = left[2];
  left[8] = down[0];
  left[5] = down[1];
  left[2] = down[2];
  down[0] = right[6];
  down[1] = right[3];
  down[2] = right[0];
  right[0] = temp0;
  right[3] = temp1;
  right[6] = temp2;
}

Cube::~Cube() {
}
