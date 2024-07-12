#include "drawable.hpp"

const std::unordered_map<std::shared_ptr<Drawable>, Drawable::Position>
    &Drawable::getChildDrawables() const {
    return children;
}

void Drawable::addChild(const std::shared_ptr<Drawable> &child, Drawable::Position p) {
    children[child] = p;
}

Drawable::Drawable(Drawable &&d) noexcept
    : color(d.color), shape(std::move(d.shape)), children(std::move(d.children)) {}

Drawable &Drawable::operator=(Drawable &&d) noexcept {
    color = d.color;
    shape = std::move(d.shape);
    children = std::move(d.children);
    return *this;
}