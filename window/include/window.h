#pragma once

#include "gl_render_helper.h"
#include "hmi_event.h"

namespace Lexi {

class window {
public:
  explicit window(int height, int width);
  void DrawWidgets(void);
  int Draw();
  void set_height(int height) { window_height_ = height; }
  void set_width(int width) { window_width_ = width; }
  int height() { return window_height_; }
  int width() { return window_width_; }
  void Init();

private:
  int window_width_ = 0;
  int window_height_ = 0;
};

} // namespace Lexi