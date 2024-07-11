#include "drawable.hpp"

const std::unordered_map<std::shared_ptr<Drawable>, Drawable::Position>
    &Drawable::getChildDrawables() const {
    return children;
}

void Drawable::addChild(const std::shared_ptr<Drawable> &child, Drawable::Position p) {
    children[child] = p;
}

void Drawable::removeChild(const std::shared_ptr<Drawable> &child) { children.erase(child); }

void Drawable::clearChildren() { children.clear(); }

Drawable::Drawable(Drawable &&d) noexcept
    : shape(std::move(d.shape)), children(std::move(d.children)), color(d.color) {}

Drawable &Drawable::operator=(Drawable &&d) noexcept {
    color = d.color;
    shape = std::move(d.shape);
    children = std::move(d.children);
    return *this;
}

Drawable::Position Drawable::Position::operator+(const Position &p) const {
    Position retVal{};
    retVal.x = x + p.x;
    retVal.y = y + p.y;
    return retVal;
}
