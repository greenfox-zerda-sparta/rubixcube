#include "cube.h"

Cube::Cube() {
  faces_of_cube.push_back(down);
  faces_of_cube.push_back(up);
  faces_of_cube.push_back(down);
  faces_of_cube.push_back(down);
  faces_of_cube.push_back(right);
  faces_of_cube.push_back(left);
}

void Cube::rotate_front() {
  char temp = down[0];
  down[0] = down[6];
  down[6] = down[8];
  down[8] = down[2];
  down[2] = temp;
  temp = down[1];
  down[1] = down[3];
  down[3] = down[7];
  down[7] = down[5];
  down[5] = temp;
 
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
  char temp = down[0];
  down[0] = down[6];
  down[6] = down[8];
  down[8] = down[2];
  down[2] = temp;
  temp = down[1];
  down[1] = down[3];
  down[3] = down[7];
  down[7] = down[5];
  down[5] = temp;
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

void Cube::rotate_down() {
  char temp = down[0];
  down[0] = down[6];
  down[6] = down[8];
  down[8] = down[2];
  down[2] = temp;
  temp = down[1];
  down[1] = down[3];
  down[3] = down[7];
  down[7] = down[5];
  down[5] = temp;

  char temp0 = front[6];
  char temp1 = front[7];
  char temp2 = front[8];
  front[6] = left[6];
  front[7] = left[7];
  front[8] = left[8];
  left[6] = back[6];
  left[7] = back[7];
  left[8] = back[8];
  back[6] = right[6];
  back[7] = right[7];
  back[8] = right[8];
  right[6] = temp0;
  right[7] = temp1;
  right[8] = temp2;
}

Cube::~Cube() {
}
  