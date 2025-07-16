#include "../include/timeline.hpp"
#include <iostream>
#include <vector>

int main() {
    Timeline timeline;
    std::vector<std::string> jsonFiles = {
        "data/timeline.json",
        "data/events_science.json",
        "data/events_inventions.json"
    };

    for (const auto& file : jsonFiles) {
        if (!timeline.loadData(file)) {
            std::cerr << "Failed to load: " << file << "\n";
        }
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
