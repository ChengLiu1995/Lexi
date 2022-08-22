#pragma once

#include <iostream>
#include <string>

#include "../../common/include/macros.h"
#include "command.h"

namespace Lexi {
class InsertCommand : public Command {
public:
  explicit InsertCommand(const std::string &char_glyph);
  ~InsertCommand() = default;
  int Execute() override;
  int UnExecute() override;

private:
  SIMPLE_FIELD(std::string, char_glyph);
};
} // namespace Lexi