#include "file.h"
#include <iostream>

std::vector<std::string> readPpData(const std::string &filePath)
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
        return ppEntries;
    }
    catch (std::string &msg)
    {
        throw std::runtime_error("Could not read file \"" + filePath + "\": " + msg);
    }
}

bool phf (std::string field, std::string ppData) {
    if (ppData.find(field) != std::string::npos) {
        return true;
    }
    return false;
}

int main () {
    auto rawPpData = readPpData("../../day4/input.csv");
    auto validCount = 0;
    for (auto const &pp : rawPpData) {
        auto valid = phf("byr", pp) && phf("iyr", pp) && phf("eyr", pp) && phf("hgt", pp) && phf("hcl", pp) && phf("ecl", pp) && phf("pid", pp);
        if (valid) {
            validCount++;
        }
    }
    std::cout << std::to_string(validCount) << std::endl;
    return 0;
}