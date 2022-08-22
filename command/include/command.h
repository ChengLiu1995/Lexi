#pragma once

#include <iostream>

namespace Lexi {
class Command {
public:
  virtual ~Command() = default;
  virtual int Execute() = 0;
  virtual int UnExecute() = 0;
};
} // namespace Lexi