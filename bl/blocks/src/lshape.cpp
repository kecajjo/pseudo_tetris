#include "lshape.hpp"

std::list<std::pair<int, int>> LShape::getShape() const {
    std::list<std::pair<int, int>> l;
    l.push_back(std::pair<int, int>(0, 0));
    l.push_back(std::pair<int, int>(1, 0));
    l.push_back(std::pair<int, int>(0, 1));
    l.push_back(std::pair<int, int>(0, 2));
    return l;
}
