#pragma once

#include "window.h"

namespace Lexi {
class Window;
class OpenglCallbackHelper {
public:
  static OpenglCallbackHelper *getInstance() {
    if (instance == nullptr)
      instance = new OpenglCallbackHelper();
    return instance;
  };
  void SetWindow(Lexi::Window *window) { window_ = window; };
  Lexi::Window *window() { return window_; };

private:
  OpenglCallbackHelper(){};
  ~OpenglCallbackHelper(){};
  OpenglCallbackHelper(const OpenglCallbackHelper &);
  OpenglCallbackHelper &operator=(const OpenglCallbackHelper &);

private:
  static OpenglCallbackHelper *instance;
  Lexi::Window *window_ = nullptr;
};

} // namespace Lexi
