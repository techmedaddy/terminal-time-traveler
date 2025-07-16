#include "../include/timeline.hpp"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    Timeline timeline;

    // Load all JSON files from the 'data' folder
    for (const auto& entry : fs::directory_iterator("data")) {
        if (entry.path().extension() == ".json") {
            if (!timeline.loadData(entry.path().string())) {
                std::cerr << "Failed to load file: " << entry.path() << "\n";
            }
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
