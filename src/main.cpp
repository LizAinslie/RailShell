#include <signal.h>
#include <iostream>
#include <string>

void shutdown(int s) {
    std::cout << "Quitting..." << std::endl;
    exit(0);
}

int main() {
    struct sigaction sigIntHandler;
    
    sigIntHandler.sa_handler = shutdown;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);

    std::cout << "Welcome to RailShell!" << std::endl;
    while(1) {
        std::cout << "> ";

        std::string line;
        std::getline(std::cin, line);

        if (line == "q") {
            shutdown(0);
        }

        std::cout << line << std::endl;
    }
}
