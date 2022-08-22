#pragma once

#include <memory>

#include "../../command/include/command_manager.h"
#include "../../common/include/macros.h"
#include "gl_render_helper.h"
#include "hmi_event.h"

namespace Lexi {

class window {
public:
  explicit window(int height, int width);
  void DrawWidgets(void);
  std::unique_ptr<CommandManager> *command_manager() {
    return &command_manager_;
  }
  int Draw();
  void Init();

private:
  SIMPLE_FIELD(int, width) = 0;
  SIMPLE_FIELD(int, height) = 0;

  std::unique_ptr<CommandManager> command_manager_ = nullptr;
};

} // namespace Lexi
