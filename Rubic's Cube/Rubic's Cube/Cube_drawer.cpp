#include "Cube_drawer.hpp"
#include "texture_functions.hpp"

Cube_drawer::Cube_drawer() {
  texture_names.resize(0);
  texture_names.push_back("pics/green.bmp");
  texture_names.push_back("pics/red.bmp");
  texture_names.push_back("pics/blue.bmp");
  texture_names.push_back("pics/orange.bmp");
  texture_names.push_back("pics/yellow.bmp");
  texture_names.push_back("pics/white.bmp");
  this->scale_x = 1;
  this->scale_y = 1;
  this->scale_z = 1;
}

Cube_drawer::~Cube_drawer() {
}

void Cube_drawer::draw_square() {
  glColor3ub(0, 153, 76);
  glBegin(GL_QUAD_STRIP);
  glVertex3d(scale_x * (0), scale_y * (0), scale_z * (0)); /// 0,0
  glVertex3d(scale_x * (0), scale_y * (0), scale_z * (1)); /// 0,1
  glVertex3d(scale_x * (1), scale_y * (0), scale_z * (0)); /// 1,0
  glVertex3d(scale_x * (1), scale_y * (0), scale_z * (1)); /// 1,1
  glEnd();
}

void Cube_drawer::draw_flattened_cube() {

  std::vector<std::pair<int, int>> script;
  script.push_back(std::make_pair(3, 0));
  script.push_back(std::make_pair(0, 0));
  script.push_back(std::make_pair(-3, 0));
  script.push_back(std::make_pair(-6, 0));
  script.push_back(std::make_pair(3, -3));
  script.push_back(std::make_pair(3, 3));

  int size = 3;
  int shift = size / 2;

  int pic = 0;

  for (int i = 0; i < 6; i++) {
    
    texture_init(texture, texture_names[pic]);
    texture_blind_and_enable(texture);

    for (int x = 0 - shift - script[i].first; x < size - shift - script[i].first; x++) {
      for (int z = 0 - shift - script[i].second; z < size - shift - script[i].second; z++) {
        glBegin(GL_POLYGON);

        glTexCoord2i(0, 0);
        glVertex3f(float(x), 0, float(z));
        glTexCoord2i(1, 0);
        glVertex3f((float(x) + 1), 0, float(z));
        glTexCoord2i(1, 1);
        glVertex3f((float(x) + 1), 0, (float(z) + 1));
        glTexCoord2i(0, 1);
        glVertex3f(float(x), 0, (float(z) + 1));

        glEnd();
      }
    }   
    texture_disable();
    texture_deinit(texture);
    pic++;
  }

}
