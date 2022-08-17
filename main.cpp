#include "Window/include/window.h"
#include <iostream>
using namespace Lexi;
int main(int argc, char *argv[]) {
  Lexi::Window new_window = Lexi::Window(1500, 1000);
  new_window.Draw();
  return 0;
}
