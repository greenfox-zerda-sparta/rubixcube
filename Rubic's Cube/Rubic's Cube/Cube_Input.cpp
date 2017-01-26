#include "Cube_Input.h"

Cube_Input::Cube_Input() {
  if (if_user_wants_input()) {
    get_input();
  }
}

void Cube_Input::help() {
  cout << "the codes for the colors are:" << endl;
  cout << "green - G\nred - R\nblue - B\norange - O\nwhite - W\nyellow - Y" << endl;
  cout << "X for restart the side" << endl;
  cout << "every other character show this help again" << endl;

}

bool Cube_Input::if_user_wants_input() {
  string what_wants = "";
  cout << "do you want to add the cube's status by hand?\n<y/n>" << endl;
  getline(cin, what_wants);
  return what_wants == "y" ? true : false;
}

void Cube_Input::get_input() {
  cout << "please put the cube down, \nwhite centered face upside,\ngreen centered face faceing you" << endl;
  cout << "enter the colors one-by-one for the ";
  for (int i = 0; i < order.size(); i++) {
    cout << order[i] << " side" << endl;
    help();
    evaluate();
  }
  cout << "finished" << endl;
}

void Cube_Input::evaluate() {
  while (side.size() < 9) {
    string color = "";
    getline(cin, color);
    switch (int(color[0])) {
    case 71:
      side.push_back(1);
      break;
    case 82:
      side.push_back(1);
      break;
    case 66:
      side.push_back(2);
      break;
    case 79:
      side.push_back(3);
      break;
    case 87:
      side.push_back(4);
      break;
    case 89:
      side.push_back(5);
      break;
    case 88:
      side.clear();
      break;
    default:
      help();
      break;
    }
  }
  users_cube.push_back(side);
  side.clear();
}

Cube_Input::~Cube_Input() {
}
