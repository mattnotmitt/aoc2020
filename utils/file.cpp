#include "file.h"

std::vector<std::string> FileUtils::readFileToStrVector(const std::string &filePath)
{
    std::ifstream infile(filePath);
    if (!infile.is_open())
    {
        throw std::runtime_error("Could not open file");
    }
    std::vector<std::string> fileContents;
    std::string line;
    try
    {
        while (std::getline(infile, line))
        {
            if (line == "\r" || line == "\n" || line.length() == 0)
                continue; // Skip line if only contains newline
            fileContents.push_back(line);
        }
        return fileContents;
    }
    catch (std::string &msg)
    {
        throw std::runtime_error("Could not read file \"" + filePath + "\": " + msg);
    }
}