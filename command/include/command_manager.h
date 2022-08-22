#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "command.h"
namespace Lexi {
class CommandManager {
public:
  CommandManager() = default;
  void AddCommand(std::unique_ptr<Command> command) {
    command->Execute();
    commands_.push_back(std::move(command));
  }

  void RemoveCommand() {
    if (commands_.empty()) {
      return;
    }
    commands_.back()->UnExecute();
    commands_.pop_back();
  }

private:
  std::vector<std::unique_ptr<Command>> commands_;
};
} // namespace Lexi