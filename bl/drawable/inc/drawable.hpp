#pragma once

#include <list>
#include <memory>
#include <tuple>
#include <utility>

class Drawable {
   public:
    struct Position {
        int x;
        int y;
    };
    struct Color {
        uint8_t r, g, b, a;
    };

    explicit Drawable(const Drawable &d);
    virtual Drawable &operator=(const Drawable &b);
    explicit Drawable(Drawable &&b);
    virtual Drawable &operator=(Drawable &&b);
    virtual ~Drawable() = default;

    virtual std::list<Position> getShape() const final { return shape; };
    virtual Color getColor() const final { return color; }

    virtual std::list<std::pair<Position, std::weak_ptr<Drawable>>> getChildDrawables() const;

   protected:
    explicit Drawable() = default;

   protected:
    Color color = {255, 255, 255, 255};
    std::list<Position> shape;
};
