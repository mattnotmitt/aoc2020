#include <iostream>
#include "file.h"
#include "convert.h"

int main()
{
    auto transactions = ConvUtils::convStrVectorToIntVector(FileUtils::readFileToStrVector(std::string("../../day1/input.csv")));
    std::vector<int> cachedTransactions;
    for (auto const &t : transactions)
    {
        for (auto const &ct : cachedTransactions)
        {
            if (t + ct == 2020)
            {
                std::cout << std::to_string(t * ct) << std::endl;
                return 0;
            }
        }
        cachedTransactions.push_back(t);
    }
    return 1;
}