#include "window/include/window.h"
#include <iostream>
using namespace Lexi;
int main(int argc, char *argv[]) {
  Lexi::window new_window = Lexi::window(1500, 1000);
  new_window.Draw();
  return 0;
}
