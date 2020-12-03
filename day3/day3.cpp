#include "file.h"
#include <iostream>

int main() {
    auto trees = 0;
    auto treeMap = FileUtils::readFileToStrVector(std::string("../../day3/input.csv"));
    auto mapWidth = treeMap.at(0).length();
    auto right = 3;
    auto down = 1;
    auto x = 0, y = 0; // +ve x is "right", +ve y is "down"
    do {
        y += down;
        x = (x += right) % mapWidth;        
        auto tree = treeMap.at(y).at(x) == '#';
        if (tree) ++trees;
    } while (y < treeMap.size() - 1);
    std::cout << trees << std::endl;
    return 0;
}