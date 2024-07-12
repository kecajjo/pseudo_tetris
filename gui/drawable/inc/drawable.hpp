#pragma once

#include <list>
#include <memory>
#include <unordered_map>

#include "color.hpp"

class Drawable {
   public:
    struct Position {
        int x;
        int y;
        Position operator+(const Position &p) const;
    };

    explicit Drawable(const Drawable &d) = default;
    Drawable &operator=(const Drawable &d) = default;
    explicit Drawable(Drawable &&d) noexcept;
    Drawable &operator=(Drawable &&d) noexcept;
    virtual ~Drawable() = default;

    std::list<Position> getShape() const { return shape; };
    Color getColor() const { return color; }

    const std::unordered_map<std::shared_ptr<Drawable>, Drawable::Position> &getChildDrawables()
        const;
    void addChild(const std::shared_ptr<Drawable> &child, Position p);
    void removeChild(const std::shared_ptr<Drawable> &child);
    void clearChildren();
    void setColor(const Color &c) { color = c; }

   protected:
    explicit Drawable() = default;

    // NOLINTNEXTLINE
    std::list<Position> shape;

   private:
    std::unordered_map<std::shared_ptr<Drawable>, Position> children;
    Color color = {Color::max_color_val, Color::max_color_val, Color::max_color_val,
                   Color::max_color_val};
};
