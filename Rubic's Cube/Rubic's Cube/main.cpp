#ifndef __FERI
#include "Opengl.hpp"
#include "Camera.hpp"
#include "Cube_drawer.hpp"
#include "User_input.hpp"

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char* argv[]) {
  std::vector<int> colors;
  colors.resize(54, 0);

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *screen;
  screen = SDL_CreateWindow("Rubic's  window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, /*SDL_WINDOW_FULLSCREEN |*/ SDL_WINDOW_OPENGL);
  SDL_GL_CreateContext(screen);

  Opengl opgl;
  Camera cam;
  Cube_drawer primitive;

  primitive.load_texture("pics/green.bmp");
  primitive.load_texture("pics/white.bmp");
  primitive.load_texture("pics/blue.bmp");
  primitive.load_texture("pics/yellow.bmp");
  primitive.load_texture("pics/red.bmp");
  primitive.load_texture("pics/orange.bmp");

  User_input ui(WIDTH, HEIGHT);
  opgl.opengl_init(WIDTH, HEIGHT);
  
  bool running = true;
  while (running) {
    ui.input_handler(running);
    opgl.opengl_sreenbuilder();
    cam.place_camera();
    cam.rotate_camera(ui.get_angle_x(), ui.get_angle_z());
    primitive.draw_flattened_cube(colors);

    opgl.opengl_display(screen);
  }

  SDL_Quit();
  return 0;
}

#endif
