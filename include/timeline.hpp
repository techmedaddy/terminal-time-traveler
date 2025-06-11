
#ifndef TIMELINE_HPP
#define TIMELINE_HPP

#include <string>
#include <unordered_map>

class Timeline {
public:
    bool loadData(const std::string& filePath);
    std::string getEvent(const std::string& year) const;
    void listYears() const;

private:
    std::unordered_map<std::string, std::string> timelineData;
};

#endif
