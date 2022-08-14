#pragma once

#include "window.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
namespace {
void SetDefaultBackGroupColor() {
  glClearColor(0.9, 0.9, 0.9, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
} // namespace
namespace Lexi {
WinDow::WinDow(int height, int width) {
  window_width_ = width;
  window_height_ = height;
}

void framebuffer_size_callback(GLFWwindow *window, int w, int h) {
  SetDefaultBackGroupColor();
}

int WinDow::Draw() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window =
      glfwCreateWindow(window_width_, window_height_, "Lexi", nullptr, nullptr);
  glfwMakeContextCurrent(window);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  if (glewInit()) {
    std::cout << "Failed to init GLEW!\n";
    return -1;
  }
  while (!glfwWindowShouldClose(window)) {
    SetDefaultBackGroupColor();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}
} // namespace Lexi
