#pragma once
#include <vector>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

class Cube_Input {
private:
  vector<string> order = {"front", "right", "back", "left", "top", "down"};
  vector<vector<int>> users_cube;
  vector<int> side;
public:
  Cube_Input();
  bool if_user_wants_input();
  void help();
  void get_input();
  void evaluate();
  ~Cube_Input();
};

