#include "file.h"
#include <iostream>
#include <sstream>
#include <map>
#include <regex>

std::vector<std::map<std::string, std::string>> readPpData(const std::string &filePath)
{
    std::ifstream infile(filePath);
    if (!infile.is_open())
    {
        throw std::runtime_error("Could not open file");
    }
    std::vector<std::string> ppEntries;
    std::string line;
    try
    {
        std::string currEntry;
        while (std::getline(infile, line))
        {
            if (line == "\r" || line == "\n" || line.length() == 0) {
                ppEntries.push_back(currEntry);
                currEntry = "";
            } else {
                currEntry += line + " ";
            }
        }
        ppEntries.push_back(currEntry);
        std::vector< std::map<std::string, std::string> > ppMaps;
        for (auto const &entry : ppEntries) {
            std::map<std::string, std::string> ppMap;
            std::istringstream entrySS(entry);
            std::string pair;
            while (std::getline(entrySS, pair, ' ')) {
                std::string key = pair.substr(0, 3);
                std::string val = pair.substr(4);
                ppMap.insert(std::pair<std::string, std::string>(key,val));
            }
            ppMaps.push_back(ppMap);
        }
        return ppMaps;
    }
    catch (std::string &msg)
    {
        throw std::runtime_error("Could not read file \"" + filePath + "\": " + msg);
    }
}


bool phf (std::string field, std::map<std::string, std::string> ppData) {
    return ppData.find(field) != ppData.end();
}

bool validateField(const std::pair<std::string, std::string> &pair) {
    try {
        auto k = pair.first;
        if (k == "byr") {
            auto v = std::stoi(pair.second);
            return 1920 <= v && v <= 2002;
        } else if (k == "iyr") {
            auto v = std::stoi(pair.second);
            return 2010 <= v && v <= 2020;
        } else if (k == "eyr") {
            auto v = std::stoi(pair.second);
            return 2020 <= v && v <= 2030;
        } else if (k == "hgt") {
            auto v = pair.second;
            auto hUnit = v.substr(v.length() - 2);
            if (hUnit == "cm") {
                auto hVal = std::stoi(v.substr(0, 3));
                return 150 <= hVal && hVal <= 193;
            } else if (hUnit == "in") {
                auto hVal = std::stoi(v.substr(0, 2));
                return 59 <= hVal && hVal <= 76;
            }
        } else if (k == "hcl") {
            auto v = pair.second;
            std::regex colourRegex("^#[0-9a-fA-F]{6}$");
            return std::regex_match(v, colourRegex);
        } else if (k == "ecl") {
            auto validEcl = std::vector<std::string>({"amb", "blu", "brn", "gry", "grn", "hzl", "oth"});
            return std::find(validEcl.begin(), validEcl.end(), pair.second) != validEcl.end();
        } else if (k == "pid") {
            auto v = pair.second;
            return std::stol(v) && v.length() == 9;
        } else if (k == "cid") {
            return true;
        }
    } catch (std::exception &e) {
        return false;
    }
    return false;
}

bool validatePp(const std::map<std::string, std::string> &pp) {
    auto present = phf("byr", pp) && phf("iyr", pp) && phf("eyr", pp) && phf("hgt", pp) 
        && phf("hcl", pp) && phf("ecl", pp) && phf("pid", pp);
    if (present) {
        auto valid = true;
        for (auto const &pair : pp) {
           valid = valid && validateField(pair);
        }
        return valid;
    }
    return false;
}

int main () {
    auto rawPpData = readPpData("../../day4/input.csv");
    auto validCount = 0;
    for (auto const &pp : rawPpData) {
        auto valid = validatePp(pp);
        if (valid) {
            validCount++;
        }
    }
    std::cout << std::to_string(validCount) << std::endl;
    return 0;
}