#include "insert_command.h"

#include <iostream>

namespace Lexi {

InsertCommand::InsertCommand(const std::string &char_glyph) {
  char_glyph_ = char_glyph;
}

int InsertCommand::Execute() {
  std::cout << "execute insert command" << std::endl;
  return 1;
}

int InsertCommand::UnExecute() {
  std::cout << "un execute insert command" << std::endl;
  return 1;
}
} // namespace Lexi