#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::vector;

vector<vector<char> > cube;

void fillCube();
void drawCube();

int main(int argc, char* argv[]) {

  fillCube();
  drawCube();


  
  return 0;
}  

void fillCube() {
  for (int i = 0; i < 6; i++) {
    vector<char> side;
    char color;
    switch (i) {
    case 0:
      color = 'B'; //blue
      break;
    case 1:
      color = 'R'; //red
      break;
    case 2:
      color = 'G'; //green
      break;
    case 3:
      color = 'O'; // orange
      break;
    case 4:
      color = 'Y'; //yellow
      break;
    case 5:
      color = 'W'; //white
      break;
    }
    for (int j = 0; j < 9; j++) {
      side.push_back(color);
    }
    cube.push_back(side);
  }
}

void drawCube() {
  for (int i = 0; i < cube.size(); i++) {
    for (int j = 0; j < cube[i].size(); j++) {
      if (j % 3 == 0) {
        cout << endl;
      }
      cout << cube[i][j] << " ";
    }
    cout << endl << endl;
  }
}