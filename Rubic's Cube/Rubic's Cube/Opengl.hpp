#pragma once
#include <iostream>
#include <Windows.h>
#include "SDL.h"
#include <glut.h>

class Opengl {
public:
  Opengl();
  ~Opengl();
  void opengl_init(int, int);
  void opengl_sreenbuilder();
  void opengl_display(SDL_Window* screen);
};



#endif
