#include "file.h"
#include <sstream>
#include <iostream>
#include <algorithm>

int main()
{
    auto pwDb = FileUtils::readFileToStrVector(std::string("../../day2/input.csv"));
    auto validCount = 0;
    for (const auto &pwRecord : pwDb)
    {
        std::istringstream pwRecordSs(pwRecord);
        std::string policyMinStr;
        std::string policyMaxStr;
        std::string policyCharStr;
        std::string pw;
        std::getline(pwRecordSs, policyMinStr, '-');
        std::getline(pwRecordSs, policyMaxStr, ' ');
        std::getline(pwRecordSs, policyCharStr, ':');
        std::getline(pwRecordSs, pw);
        pw.erase(0,1); // Get rid of extra space
        
        char policyChar = policyCharStr.at(0);

        auto policyMin = std::stoi(policyMinStr) - 1;
        auto policyMax = std::stoi(policyMaxStr) - 1;
        
        if ((pw.at(policyMin) == policyChar) != (pw.at(policyMax) == policyChar)) {
            validCount++;
        }
    }
    std::cout << std::to_string(validCount) << std::endl;
    return 0;
}