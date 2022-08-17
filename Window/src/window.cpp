#include "window.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

#include "button.h"

namespace {
void SetDefaultBackGroupColor() {
  glClearColor(0.9, 0.9, 0.9, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT); //清空颜色缓冲池
  Lexi::OpenglCallbackHelper *helper =
      Lexi::OpenglCallbackHelper::getInstance();
  helper->window()->DrawWidgets();
  glFlush();
}

void Reshape(int w, int h) {
  glViewport(0, 0, w, h);
  Lexi::OpenglCallbackHelper *helper =
      Lexi::OpenglCallbackHelper::getInstance();
  helper->window()->set_height(h);
  helper->window()->set_width(w);
}
} // namespace

namespace Lexi {
Window::Window(int height, int width) {
  window_width_ = width;
  window_height_ = height;
  Init();
}

void Window::Init() {
  int argc = 1;
  char arg0[] = "fake";
  char **fake_argv = new char *[2] { arg0 };
  glutInit(&argc, fake_argv);
}

void Window::DrawWidgets(void) {
  ButtonWidget button = ButtonWidget(0, 0);
  button.Draw(this);
}

int Window::Draw() {
  OpenglCallbackHelper *helper = OpenglCallbackHelper::getInstance();
  helper->SetWindow(this);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.
  glutInitWindowPosition(500, 500); // Set top-left display-window position.
  glutInitWindowSize(window_width_,
                     window_height_); // Set display-window width and height.
  glutCreateWindow("Lexi");           // Create display window.
  SetDefaultBackGroupColor();
  glutReshapeFunc(Reshape);
  glutDisplayFunc(display); // Send graphics to display window.
  glutMainLoop();

  return 0; // Display everything and wait.
}
} // namespace Lexi
