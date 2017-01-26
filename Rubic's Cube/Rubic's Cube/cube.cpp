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
  char temp;
  temp = front[0];
  front[0] = front[6];
  front[6] = front[8];
  front[8] = front[2];
  front[2] = temp;
  temp = front[1];
  front[1] = front[3];
  front[3] = front[7];
  front[7] = front[5];
  front[5] = temp;

}

void Cube::change(int first, int second) {

}

Cube::~Cube() {
}
