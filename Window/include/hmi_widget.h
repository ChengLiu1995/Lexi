#pragma once

#include "window.h"

namespace Lexi {
class HmiWidget {
public:
  HmiWidget() = default;
  virtual ~HmiWidget() = default;
  virtual void Draw(Window *Window){};
  virtual void OnEvent(){};

protected:
  int x_ = 0;
  int y_ = 0;
  int width_ = 0;
  int height_ = 0;
};

} // namespace Lexi
