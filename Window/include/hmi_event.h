#pragma once

#include <string>

#include "../../common/include/macros.h"
#include "window.h"

enum MouseEvent {
  MOUSE_NO_EVENT = 0,
  LEFT_MOUSE_UP = 1,
  LEFT_MOUSE_DOWN = 2,
  RIGHT_MOUSE_UP = 3,
  RIGHT_MOUSE_DOWN = 4
};

enum SpecialKeyEvent { SK_NO_EVENT = 0, CONTROL_DOWN = 1 };

namespace Lexi {
class HmiEvent {
public:
  HmiEvent() = default;
  virtual ~HmiEvent() = default;
  static HmiEvent *getInstance() {
    if (instance == nullptr)
      instance = new HmiEvent();
    return instance;
  };
  void Reset() {
    mouse_event_ = MouseEvent::MOUSE_NO_EVENT;
    special_key_event_ = SpecialKeyEvent::SK_NO_EVENT;
    key_event_.clear();
  }

private:
  SIMPLE_FIELD(MouseEvent, mouse_event) = MouseEvent::MOUSE_NO_EVENT;
  SIMPLE_FIELD(SpecialKeyEvent,
               special_key_event) = SpecialKeyEvent::SK_NO_EVENT;
  SIMPLE_FIELD(std::string, key_event) = "";
  static HmiEvent *instance;
};

} // namespace Lexi
