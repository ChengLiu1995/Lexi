#pragma once

#include "window.h"

namespace Lexi {
class window;
class OpenglCallbackHelper {
public:
  static OpenglCallbackHelper *getInstance() {
    if (instance == nullptr)
      instance = new OpenglCallbackHelper();
    return instance;
  };
  void SetWindow(Lexi::window *window) { window_ = window; };
  Lexi::window *window() { return window_; };

private:
  OpenglCallbackHelper(){};
  ~OpenglCallbackHelper(){};
  OpenglCallbackHelper(const OpenglCallbackHelper &);
  OpenglCallbackHelper &operator=(const OpenglCallbackHelper &);

private:
  static OpenglCallbackHelper *instance;
  Lexi::window *window_ = nullptr;
};

} // namespace Lexi
