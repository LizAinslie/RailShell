#include <signal.h>
#include <iostream>
#include <string>

#include "colors.h"

void prefix_out() {
	std::cout
		<< Color::FG_LIGHT_BLUE
		<< "\u25b6 "
		<< Color::FG_DEFAULT;
}

void prefix_in() {
	std::cout
		<< Color::FG_GREEN
		<< "\u25c0 "
		<< Color::FG_DEFAULT;
}

void shutdown(int s) {
	if (s != 0) std::cout << std::endl;
	prefix_out();

	std::cout
		<< Color::FG_LIGHT_RED
		<< "Quitting..."
		<< Color::FG_DEFAULT
		<< std::endl;

	exit(0);
}

int main() {
	struct sigaction sigIntHandler;

	sigIntHandler.sa_handler = shutdown;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;

	sigaction(SIGINT, &sigIntHandler, NULL);

	prefix_out();
	std::cout
		<< Color::FG_YELLOW
		<< "Welcome to RailShell!"
		<< Color::FG_DEFAULT
		<< std::endl;

	while(1) {
		prefix_in();

		std::string line;
		std::getline(std::cin, line);

		if (line == "q") shutdown(0);

		prefix_out();
		std::cout << line << std::endl;
	}
}
