#include "Opengl.hpp"
#include "Camera.hpp"
#include "Cube_drawer.hpp"
#include "User_input.hpp"
#include "cube.h"
#include "Start_Window.h"

#define WIDTH 640
#define HEIGHT 480

int main_(int argc, char* argv[]) {
  Cube my_cube;
    bool cheater = false;

    bool start_running = true;
  
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *screen;
    screen = SDL_CreateWindow("Rubic's  window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, /*SDL_WINDOW_FULLSCREEN |*/ SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(screen);
    Opengl opgl;
    Camera cam;
    Cube_drawer primitive;
    primitive.load_texture("pics/green.bmp");
    primitive.load_texture("pics/orange.bmp");///
    primitive.load_texture("pics/blue.bmp");
    primitive.load_texture("pics/red.bmp");///
    primitive.load_texture("pics/white.bmp");
    primitive.load_texture("pics/yellow.bmp");
    User_input ui(WIDTH, HEIGHT);
    opgl.opengl_init(WIDTH, HEIGHT);
    bool solver = false;
    bool running = true;
    while (running) {
      ui.input_handler(running, solver, my_cube);
      opgl.opengl_sreenbuilder();
      cam.place_camera();
      cam.rotate_camera(ui.get_angle_x(), ui.get_angle_z());

      if (solver) {

        SDL_Delay(800);
        my_cube.undo_last_step();
        primitive.draw_real_cube(my_cube.get_vector_for_Lego(), 3);
        if (my_cube.trackback.empty()) {
          solver = false;
          cheater = true;
        }
      }
      else {
        primitive.draw_real_cube(my_cube.get_vector_for_Lego(), 3);
      }

      primitive.draw_background();
      opgl.opengl_display(screen);
     
    }
    
  return 0;

}