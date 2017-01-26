#include "Cube_drawer.hpp"
#include "texture_functions.hpp"

Cube_drawer::Cube_drawer() {
  texture_names.resize(0);
  texture_names.push_back("pics/blue.bmp");
  texture_names.push_back("pics/green.bmp");
  texture_names.push_back("pics/orange.bmp");
  texture_names.push_back("pics/red.bmp");
  texture_names.push_back("pics/white.bmp");
  texture_names.push_back("pics/yellow.bmp");
  this->scale_x = 1;
  this->scale_y = 1;
  this->scale_z = 1;
}

Cube_drawer::~Cube_drawer() {
}

void Cube_drawer::generate_map(int _beg, int repeat, int x, int z, char ax, int pic) {
  int beg = _beg;
  int end = beg + 2;
 
  texture_init(texture, texture_names[pic]);
  texture_blind_and_enable(texture);

  glBegin(GL_QUAD_STRIP);
  //glColor3ub(0, 153, 76);
  for (int j = beg + z; j < end + z; j++) {
    for (int i = beg + x; i < end + x; i++) {
      glTexCoord2f(i, j);
      glVertex3d(double(i), 0, double(j));
    }
  }
  glEnd();

  texture_disable();
  texture_deinit(texture);
  
  switch (ax) {
  case 'x':
    x++;
    z = 0;
    ax = 'z';
    break;
  case 'z':
    z++;
    x = 0;
    ax = 'd';
    break;
  case 'd':
    x++;
    // z++;
    ax = 'x';
    break;
  }
  repeat--;
  pic++;
  
  if (pic > texture_names.size() - 1) {
    pic = 0;
  }
  if (repeat < 0) {
    return;
  }
  else {
    generate_map(beg, repeat, x, z, ax, pic);
  }
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

void Cube_drawer::generate_tile_net(int size) {
  bool color = true;
  if (size % 2 != 0) {
    size++;
  }
  int shift = size / 2;
  for (int x = 0 - shift; x < size - shift; x++) {
    for (int z = 0 - shift; z < size - shift; z++) {
      if (color)
        glColor3f(1, 1, 1);
      else
        glColor3f(0, 0, 0);
      color = !color;
      glBegin(GL_POLYGON);
      glVertex3i(x, 0, z);
      glVertex3i((x + 1), 0, z);
      glVertex3i((x + 1), 0, (z + 1));
      glVertex3i(x, 0, (z + 1));
      glEnd();
    }
    if (size % 2 == 0) color = !color;
  }
}

void Cube_drawer::draw_flattened_cube() {

  std::vector<std::pair<int, int>> script;
  script.push_back(std::make_pair(0, 0));
  script.push_back(std::make_pair(0, 3));
  script.push_back(std::make_pair(0, 6));
  script.push_back(std::make_pair(0, 9));
  script.push_back(std::make_pair(3, 3));
  script.push_back(std::make_pair(-3, 3));

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