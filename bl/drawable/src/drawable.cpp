#include "drawable.hpp"

std::list<std::pair<Drawable::Position, std::weak_ptr<Drawable>>> Drawable::getChildDrawables() const {
    return std::list<std::pair<Position, std::weak_ptr<Drawable>>>();
}