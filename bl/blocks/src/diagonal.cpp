#include "diagonal.hpp"

Diagonal::Diagonal() {
    shape.push_back(Drawable::Position{0, 0});
    shape.push_back(Drawable::Position{1, 1});
    shape.push_back(Drawable::Position{2, 2});
    shape.push_back(Drawable::Position{3, 3});
}
