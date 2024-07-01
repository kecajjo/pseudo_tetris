#pragma once

#include <list>
#include <memory>
#include <tuple>
#include <unordered_map>
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
    virtual Drawable &operator=(const Drawable &d);
    explicit Drawable(Drawable &&d);
    virtual Drawable &operator=(Drawable &&d);
    virtual ~Drawable() = default;

    std::list<Position> getShape() const { return shape; };
    Color getColor() const { return color; }

    const std::unordered_map<std::shared_ptr<Drawable>, Drawable::Position> getChildDrawables()
        const;
    void addChild(std::shared_ptr<Drawable> child, Position p);

   protected:
    explicit Drawable() = default;

   protected:
    Color color = {255, 255, 255, 255};
    std::list<Position> shape;
    std::unordered_map<std::shared_ptr<Drawable>, Position> children;
};
