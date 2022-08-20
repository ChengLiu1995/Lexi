#include "window.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

#include "button.h"
#include "hmi_event.h"

namespace {
void SetDefaultBackGroupColor() {
  glClearColor(0.9, 0.9, 0.9, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void display(void) {
  Lexi::HmiEvent *hmi_event = Lexi::HmiEvent::getInstance();
  if (hmi_event->special_key_event() == SpecialKeyEvent::CONTROL_DOWN) {
    std::cout << "ctrl down" << std::endl;
  }
  if (hmi_event->key_event().size()) {
    std::cout << "key down on :" << hmi_event->key_event() << std::endl;
  }
  if (hmi_event->mouse_event() == MouseEvent::LEFT_MOUSE_DOWN) {
    std::cout << "left mouse down" << std::endl;
  }
  if (hmi_event->mouse_event() == MouseEvent::LEFT_MOUSE_UP) {
    std::cout << "left mouse up" << std::endl;
  }
  if (hmi_event->special_key_event() == SpecialKeyEvent::CONTROL_DOWN &&
      hmi_event->key_event() == "c") {
    std::cout << "ctrl+c down" << std::endl;
  }

  glClear(GL_COLOR_BUFFER_BIT); //清空颜色缓冲池
  Lexi::OpenglCallbackHelper *helper =
      Lexi::OpenglCallbackHelper::getInstance();
  helper->window()->DrawWidgets();
  glFlush();
}

void SpecialKeyUp(int key, int x, int y) {
  Lexi::HmiEvent *hmi_event = Lexi::HmiEvent::getInstance();
  hmi_event->set_special_key_event(SpecialKeyEvent::SK_NO_EVENT);
  display();
}

void SpecialKey(int key, int x, int y) {
  Lexi::HmiEvent *hmi_event = Lexi::HmiEvent::getInstance();
  // if (key == GLUT_KEY_F1) {
  // }
  if (key == 114) {
    hmi_event->set_special_key_event(SpecialKeyEvent::CONTROL_DOWN);
  }
  display();
}
void KeyBoards(unsigned char key, int x, int y) {
  Lexi::HmiEvent *hmi_event = Lexi::HmiEvent::getInstance();
  std::string key_event(1, key);
  hmi_event->set_key_event(key_event);
  if ((glutGetModifiers() == GLUT_ACTIVE_CTRL) &&
      (key == 'c' || key == 'C' || key == '\x03')) {
    hmi_event->set_key_event("c");
  }
  display();
}

// void mouseMove(int x, int y) { printf("mouse moving，x:%d,y%d\n", x, y); }

void mouseClick(int btn, int state, int x, int y) {
  Lexi::HmiEvent *hmi_event = Lexi::HmiEvent::getInstance();
  if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    hmi_event->set_mouse_event(MouseEvent::LEFT_MOUSE_DOWN);
  }
  if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {
    hmi_event->set_mouse_event(MouseEvent::LEFT_MOUSE_UP);
  }
  if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
    hmi_event->set_mouse_event(MouseEvent::RIGHT_MOUSE_DOWN);
  }
  if (btn == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
    hmi_event->set_mouse_event(MouseEvent::RIGHT_MOUSE_UP);
  }
  display();
}

void idle(void) {
  Lexi::HmiEvent::getInstance()->Reset();
  display();
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
window::window(int height, int width) {
  window_width_ = width;
  window_height_ = height;
  Init();
}

void window::Init() {
  int argc = 1;
  char arg0[] = "fake";
  char **fake_argv = new char *[2] { arg0 };
  glutInit(&argc, fake_argv);
}

void window::DrawWidgets(void) {
  ButtonWidget button = ButtonWidget(0, 0);
  button.Draw(this);
}

int window::Draw() {
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
  glutMouseFunc(mouseClick);
  // glutMotionFunc(mouseMove);
  glutIdleFunc(idle);
  glutSpecialFunc(&SpecialKey);
  glutKeyboardFunc(&KeyBoards);
  glutSpecialUpFunc(&SpecialKeyUp);
  glutMainLoop();

  return 0; // Display everything and wait.
}
} // namespace Lexi
