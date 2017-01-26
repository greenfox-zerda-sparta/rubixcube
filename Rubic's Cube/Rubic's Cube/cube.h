#pragma once

#include <vector>

using std::vector;

class Cube {
private:
  vector<vector<char>> faces_of_cube;
  vector<char> up = {'W','W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'};
  vector<char> front = {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'};
  vector<char> down = {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'};
  vector<char> back = {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'};
  vector<char> right = {'R','R','R','R','R','R','R','R','R' };
  vector<char> left = {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'};
public:
  Cube();
  void rotate_front();
  void rotate_up();
  void rotate_back();
  void rotate_down();
  void rotate_right();
  void roatate_left();
  ~Cube();
private:
  void change(int, int);
};

