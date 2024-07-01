#include "tshape.hpp"

TShape::TShape() {
    shape.push_back(Drawable::Position{0, 0});
    shape.push_back(Drawable::Position{-1, 1});
    shape.push_back(Drawable::Position{0, 1});
    shape.push_back(Drawable::Position{1, 1});
}
