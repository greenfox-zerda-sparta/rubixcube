#include "Opengl.hpp"
#include "Camera.hpp"
#include "Cube_drawer.hpp"
#include "User_input.hpp"
#include "cube.h"
#include "Start_Window.h"

#define WIDTH 640
#define HEIGHT 480

bool is_inside(int x, int y, SDL_Rect current) {
  if (x < current.x) {
    return false;
  }
  else if (x > current.x + current.w) {
    return false;
  }
  else if (y < current.y) {
    return false;
  }
  else if (y > current.y + current.h) {
    return false;
  }
  return true;
}

int which_button(int x, int y, vector<SDL_Rect> buttons) {
  for (int i = 0; i < buttons.size(); i++) {
    SDL_Rect current = buttons[i];
    if (is_inside(x, y, current)) {
      return i;
    }
  }
}

void ending(std::string pic_path) {
  SDL_Window* window = SDL_CreateWindow("winner", 0, 30, 640, 480, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Surface* surface = IMG_Load(pic_path.c_str());
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect new_game = {100, 301, 150, 50};
  SDL_Rect quit = { 343, 303, 150, 50};
  SDL_Event event;
  bool winrunner = true;
  while (winrunner) {
    while (SDL_PollEvent(&event)) {
      int x, y;
      if (event.type == SDL_MOUSEBUTTONDOWN) {
        SDL_GetMouseState(&x, &y);
        if (is_inside(x, y, new_game)) {
          //new game
        }
        else if (is_inside(x, y, quit)) {
          //quit
        }
      }
      else if (event.type == SDL_QUIT) {
        winrunner = false;
        break;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }


}

int main(int argc, char* argv[]) {

  Cube my_cube;
  bool cheater = false;

  //kristof bindzsi eleje
  {  Start_Window start_window;
  SDL_Event event;
  vector<SDL_Rect> buttons;
  SDL_Rect easy = { 40, 130, 150, 50 };
  buttons.push_back(easy);
  SDL_Rect medium = { 240, 130, 150, 50 };
  buttons.push_back(medium);
  SDL_Rect hard = { 450, 130, 150, 50 };
  buttons.push_back(hard);

  bool start_running = true;
  while (start_running) {
    while (SDL_PollEvent(&event)) {
      int x, y;
      switch (event.type) {
      case SDL_QUIT:
        start_running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          start_running = false;
          break;
        }
      case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&x, &y);
        switch (which_button(x, y, buttons)) {
        case 0: {
          cout << "easy" << endl;
          SDL_DestroyWindow(start_window.window);
          my_cube.random_shuffle(5);
          start_running = false;
          break;
        }
        case 1: {
          cout << "medium" << endl;
          //SDL_DestroyWindow(start_window.window);
          my_cube.random_shuffle(10);
          start_running = false;
          break;
        }
        case 2: {
          cout << "hard" << endl;
          //SDL_DestroyWindow(start_window.window);
          my_cube.random_shuffle(20);
          start_running = false;
          break;
        }
        }
        break;
      }
    }
    start_window.render();
  }
  //kristof binzsi vege
  }

  // lego bindzsije
  {  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *screen;
  screen = SDL_CreateWindow("Rubic's  window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, /*SDL_WINDOW_FULLSCREEN |*/ SDL_WINDOW_OPENGL);
  SDL_GL_CreateContext(screen);
  Opengl opgl;
  Camera cam;
  Cube_drawer primitive;
  primitive.load_texture("pics/green.bmp");
  primitive.load_texture("pics/red.bmp");
  primitive.load_texture("pics/blue.bmp");
  primitive.load_texture("pics/orange.bmp");
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

    if (my_cube.is_ready()) {
      running = false;
    }
  }
  // lego bindzsi vege
  }

  //feco binzsi start
  {
    if (cheater) {
      ending("onemore.jpg");
    }
    else {
      ending("youwon.jpg");
    }
    //feco binzsi end
  }
  //feco bindzsi end

  SDL_Quit();
  return 0;
}