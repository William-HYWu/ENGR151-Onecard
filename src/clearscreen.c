#include "clearscreen.h"

void clearscreen(void) {
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
  // Clear console on Unix-like systems
  system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
  // Clear console on Windows
  system("cls");
#endif
}
