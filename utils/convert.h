#pragma once

/**
 * @file Utils to aid with converting data
 */

#include <vector>
#include <string>
#include <system_error>

namespace ConvUtils
{
    std::vector<int> convStrVectorToIntVector(std::vector<std::string> strVector);
}