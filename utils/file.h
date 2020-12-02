#pragma once

/**
 * @file Utils to aid with file handling in AOC puzzles
 */

#include <fstream>
#include <vector>
#include <string>

namespace FileUtils
{
    std::vector<std::string> readFileToStrVector(const std::string &filePath);
}