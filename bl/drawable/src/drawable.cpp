#include "drawable.hpp"

const std::unordered_map<std::shared_ptr<Drawable>, Drawable::Position> Drawable::getChildDrawables() const {
    return children;
}

void Drawable::addChild(std::shared_ptr<Drawable> child, Drawable::Position p){
    children[child] = p;
}