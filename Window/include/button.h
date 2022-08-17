#pragma once

#include "hmi_widget.h"

#include <string>

namespace Lexi {
class ButtonWidget : public HmiWidget {
public:
  explicit ButtonWidget(int x, int y, const std::string name = "Button");
  void Draw(Window *Window) override;
  void OnEvent() override{};

private:
  std::string name_ = "Button";
};

} // namespace Lexi
