#include "button.h"
#include <iostream>

#include <GL/glut.h>

namespace {
constexpr int kButtonHeight = 20;
constexpr int kButtonWidth = 60;
} // namespace

namespace Lexi {
ButtonWidget::ButtonWidget(int x, int y, const std::string name) {
  height_ = kButtonHeight;
  width_ = kButtonWidth;
  x_ = x;
  y_ = y;
  name_ = name;
}
void ButtonWidget::Draw(window *window) {
  //   y
  //   ^
  //   |
  //   |
  //   |
  //   ----------->x
  float button_height = 30;
  float button_width = 60;
  int name_width = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24,
                                    (const unsigned char *)name_.c_str());
  button_width = std::max(button_width, (float)name_width + 6);
  glViewport(0, 0, window->width(), window->height());
  glRasterPos2f(0, 0);
  glLoadIdentity();
  glOrtho(0.0f, window->width(), 0.0f, window->height(), 1.0f, -1.0f);
  glBegin(GL_QUADS);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(x_, window->height() - y_, 0.0f);                // top left
  glVertex3f(x_ + button_width, window->height() - y_, 0.0f); // top right
  glVertex3f(x_ + button_width, window->height() - y_ - button_height,
             0.0f);                                            // bot right
  glVertex3f(x_, window->height() - y_ - button_height, 0.0f); // bot left
  glEnd();

  glViewport(x_, window->height() - y_ - button_height, window->width(),
             window->height());
  glColor3f(1.0f, 0.0f, 0.0f);
  glRasterPos2f(3, 5);
  for (int k = 0; k < name_.size(); k++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name_[k]);
  }
  glEnd();
}
}; // namespace Lexi
