
#include "../include/timeline.hpp"
#include <iostream>

int main() {
    Timeline timeline;

    if (!timeline.loadData("data/timeline.json")) {
        std::cerr << "Failed to load timeline data.\n";
        return 1;
    }

    std::string input;
    std::cout << "Welcome to Terminal Time Traveler! Type 'list', a year, or 'exit'.\n";

    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, input);

        if (input == "exit") break;
        else if (input == "list") timeline.listYears();
        else std::cout << timeline.getEvent(input) << "\n";
    }

    return 0;
}
