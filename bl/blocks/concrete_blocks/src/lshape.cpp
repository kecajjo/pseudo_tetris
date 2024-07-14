#include "lshape.hpp"

LShape::LShape() {
    shape.push_back(Drawable::Position{0, 0});
    shape.push_back(Drawable::Position{1, 0});
    shape.push_back(Drawable::Position{0, 1});
    shape.push_back(Drawable::Position{0, 2});
}
