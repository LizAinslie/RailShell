//
// Created by Landon Gravat
//

#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

#include "colors.h"

void prefix_out() {
  std::cout << Color::FG_LIGHT_BLUE << "\u25b6 " << Color::FG_DEFAULT;
}

void prefix_in() {
  std::cout << Color::FG_GREEN << "\u25c0 " << Color::FG_DEFAULT;
}

void exec(const char *cmd) {
  std::array<char, 128> buffer;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);

  if (!pipe) {
    prefix_out();
    std::cout << Color::FG_RED << "popen() failed!" << Color::FG_DEFAULT
              << std::endl;
  }

  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    prefix_out();
    std::cout << buffer.data();
  }
}

void shutdown() {
  prefix_out();

  std::cout << Color::FG_LIGHT_RED << "Quitting..." << Color::FG_DEFAULT
            << std::endl;
}

int main() {
  prefix_out();
  std::cout << Color::FG_YELLOW << "Welcome to RailShell!" << Color::FG_DEFAULT
            << std::endl;

  prefix_out();
  std::cout << Color::FG_YELLOW << "RailShell is a colorful shell made by RailRunner16." << Color::FG_DEFAULT
            << std::endl;

  prefix_out();
  std::cout << Color::FG_YELLOW << "Email: railinator4903@gmail.com" << Color::FG_DEFAULT
            << std::endl;

  while (1) {
    prefix_in();

    std::string line;
    std::getline(std::cin, line);

    if (line == "q") {
      shutdown();
      break;
    }

    // prefix_out();
    // std::cout << line << std::endl;

    exec(line.c_str());
  }

  return 0;
}
