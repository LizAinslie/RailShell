//
// Created by Landon Gravat
//

#include <ostream>

namespace Color {
enum Code {
  // Formats
  BOLD = 1,
  DIM = 2,
  UNDERLINE = 4,
  BLINK = 5,
  INVERT = 7,
  HIDDEN = 8,

  // Resets
  RESET = 0,

  // Foreground Colors
  FG_DEFAULT = 39,
  FG_BLACK = 30,
  FG_RED = 31,
  FG_GREEN = 32,
  FG_YELLOW = 33,
  FG_BLUE = 34,
  FG_MAGENTA = 35,
  FG_CYAN = 36,
  FG_LIGHT_GRAY = 37,
  FG_DARK_GRAY = 90,
  FG_LIGHT_RED = 91,
  FG_LIGHT_GREEN = 92,
  FG_LIGHT_YELLOW = 93,
  FG_LIGHT_BLUE = 94,
  FG_LIGHT_MAGENTA = 95,
  FG_LIGHT_CYAN = 96,
  FG_WHITE = 97,

  // Background Colors
  BG_RED = 41,
  BG_GREEN = 42,
  BG_BLUE = 44,
  BG_DEFAULT = 49
};

std::ostream &operator<<(std::ostream &os, Code code) {
  return os << L"\033[" << static_cast<int>(code) << L"m";
}
} // namespace Color