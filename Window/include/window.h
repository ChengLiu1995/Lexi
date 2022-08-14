#pragma once

namespace Lexi {
class WinDow {
public:
  explicit WinDow(int height, int width);
  int Draw();

private:
  int window_width_ = 0;
  int window_height_ = 0;
};

} // namespace Lexi
