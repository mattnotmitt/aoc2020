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
            for (auto const &ct2 : cachedTransactions)
            {
                if (ct2 == ct)
                    continue;
                if (t + ct + ct2 == 2020)
                {
                    std::cout << std::to_string(t)
                              << "*" << std::to_string(ct)
                              << "*" << std::to_string(ct2)
                              << "=" << std::to_string(t * ct * ct2) << std::endl;
                    return 0;
                }
            }
        }
        cachedTransactions.push_back(t);
    }
    return 1;
}