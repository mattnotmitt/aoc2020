#include "file.h"
#include <iostream>

int treesEncountered(int right, int down, const std::vector<std::string> &treeMap) {
    auto trees = 0;
    auto mapWidth = treeMap.at(0).length();
    auto x = 0, y = 0; // +ve x is "right", +ve y is "down"
    do {
        y += down;
        x = (x += right) % mapWidth;        
        auto tree = treeMap.at(y).at(x) == '#';
        if (tree) ++trees;
    } while (y < treeMap.size() - 1);
    std::cout << trees << std::endl;
    return trees;
}

int main() {
    auto treeMap = FileUtils::readFileToStrVector(std::string("../../day3/input.csv"));
    long slope0 = treesEncountered(1, 1, treeMap);
    long slope1 = treesEncountered(3, 1, treeMap);
    long slope2 = treesEncountered(5, 1, treeMap);
    long slope3 = treesEncountered(7, 1, treeMap);
    long slope4 = treesEncountered(1, 2, treeMap);
    long product = slope0 * slope1 * slope2 * slope3 * slope4;
    std::cout << product << std::endl;
}
