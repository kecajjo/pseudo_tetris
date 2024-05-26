#include "diagonal.hpp"

std::list<std::pair<int, int>> Diagonal::getShape() const {
    std::list<std::pair<int, int>> l;
    l.push_back(std::pair<int, int>(0, 0));
    l.push_back(std::pair<int, int>(1, 1));
    l.push_back(std::pair<int, int>(2, 2));
    l.push_back(std::pair<int, int>(3, 3));
    return l;
}
