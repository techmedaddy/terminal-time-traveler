
#include "../include/timeline.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

bool Timeline::loadData(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) return false;

    json j;
    file >> j;

    for (auto& [year, event] : j.items()) {
        timelineData[year] = event;
    }
    return true;
}

std::string Timeline::getEvent(const std::string& year) const {
    auto it = timelineData.find(year);
    if (it != timelineData.end()) return it->second;
    return "No alternate timeline event found for this year.";
}

void Timeline::listYears() const {
    std::cout << "Available Years in Alternate Timeline:\n";
    for (const auto& [year, _] : timelineData) {
        std::cout << "- " << year << "\n";
    }
}
