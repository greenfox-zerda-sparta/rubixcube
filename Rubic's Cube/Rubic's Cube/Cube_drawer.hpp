#pragma once
#include <vector>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>
#include <utility>

class Cube_drawer {
private:
  GLuint texture;
  std::vector<GLuint> textures;
  std::vector<std::pair<int, int>> script;

  double scale_x;
  double scale_y;
  double scale_z;
public:
  Cube_drawer();
  ~Cube_drawer();
  void load_texture(char* file_name);
  void draw_square();
  void draw_flattened_cube();
};

