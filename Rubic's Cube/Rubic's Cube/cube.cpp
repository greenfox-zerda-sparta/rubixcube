#include "cube.h"

Cube::Cube() {
  faces_of_cube.push_back(back);
  faces_of_cube.push_back(up);
  faces_of_cube.push_back(back);
  faces_of_cube.push_back(down);
  faces_of_cube.push_back(right);
  faces_of_cube.push_back(left);
}

void Cube::rotate_front() {
  char temp = back[0];
  back[0] = back[6];
  back[6] = back[8];
  back[8] = back[2];
  back[2] = temp;
  temp = back[1];
  back[1] = back[3];
  back[3] = back[7];
  back[7] = back[5];
  back[5] = temp;
 
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

void Cube::rotate_back() {
  char temp = back[0];
  back[0] = back[6];
  back[6] = back[8];
  back[8] = back[2];
  back[2] = temp;
  temp = back[1];
  back[1] = back[3];
  back[3] = back[7];
  back[7] = back[5];
  back[5] = temp;
  char temp0 = up[2];
  char temp1 = up[1];
  char temp2 = up[0];
  up[2] = right[8];
  up[1] = right[5];
  up[0] = right[2];
  right[8] = down[6];
  right[5] = down[7];
  right[2] = down[8];
  down[6] = left[0];
  down[7] = left[3];
  down[8] = left[6];
  left[0] = temp0;
  left[3] = temp1;
  left[6] = temp2;
}

Cube::~Cube() {
}
  