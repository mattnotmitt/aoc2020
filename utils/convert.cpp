#include "convert.h"

std::vector<int> ConvUtils::convStrVectorToIntVector(std::vector<std::string> strVector)
{
    std::vector<int> intVector;
    int lineCount = 1;
    for (const auto &str : strVector)
    {
        try
        {
            intVector.push_back(std::stoi(str));
            ++lineCount;
        }
        catch (std::string &msg)
        {
            throw std::runtime_error("Line " + std::to_string(lineCount) + ": Could not convert string \"" + str + "\" to int");
        }
    }
    return intVector;
}