#pragma once
#include <vector>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>
#include <utility>

class Cube_drawer {
private:
  GLuint texture;
  std::vector<char*> texture_names;
  double scale_x;
  double scale_y;
  double scale_z;
public:
  Cube_drawer();
  ~Cube_drawer();
  void draw_square();
  void draw_flattened_cube();
};

