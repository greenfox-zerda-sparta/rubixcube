#include "Opengl.hpp"
#include "Camera.hpp"
#include "Axes.hpp"
#include "Map.hpp"
#include "User_input.hpp"

#include <iostream>
#define WIDTH 640
#define HEIGHT 480
double angle_x = 0;
double angle_z = 0;

int main(int argc, char* argv[]) {
  Opengl opgl;
  Camera cam;
  Map quad_map;
  User_input ui(WIDTH, HEIGHT);
  
  opgl.opengl_init(WIDTH, HEIGHT);
  

  bool running = true;
  int repeat = 1;
  while (running) {
    ui.input_handler(running);
    opgl.opengl_sreenbuilder();
    cam.place_camera();
    cam.rotate_camera(ui.get_angle_x(), ui.get_angle_z());
    quad_map.generate_tile_net(ui.get_repeat());    
    opgl.opengl_display();
  }

  SDL_Quit();
  return 0;
}