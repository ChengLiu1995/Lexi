#include "Window/include/window.h"
#include <iostream>
using namespace Lexi;
int main(int argc, char *argv[]) {
  Lexi::WinDow new_window = Lexi::WinDow(800, 1000);
  new_window.Draw();
  return 0;
}
