#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <string>

#ifdef _WIN32
#define WIN true
#else
#define WIN false
#endif

#include "colors.h"

void prefix_out() {
  std::wcout << Color::FG_LIGHT_BLUE << L"\u25b6 " << Color::FG_DEFAULT;
}

void prefix_in() {
  std::wcout << Color::FG_GREEN << L"\u25c0 " << Color::FG_DEFAULT;
}

void shutdown() {
  prefix_out();

  std::wcout << Color::FG_LIGHT_RED << "Quitting..." << Color::FG_DEFAULT
             << std::endl;

  exit(0);
}

int main() {
  _setmode(_fileno(stdout), _O_U8TEXT);

  prefix_out();
  std::wcout << Color::FG_YELLOW << "Welcome to RailShell!" << Color::FG_DEFAULT
             << std::endl;

  while (1) {
    prefix_in();

    std::string line;
    std::getline(std::cin, line);

    if (line == "q")
      shutdown();

    prefix_out();
    std::cout << line << std::endl;
  }

  return 0;
}
