#pragma once

#include <limits>
#include <list>
#include <memory>
#include <unordered_map>

// TODO temp struct, will be removed in the next PR
struct Color {
    int r, g, b, a;
    Color() : r(0), g(0), b(0), a(0) {}
    Color(const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha)
        : r(red), g(green), b(blue), a(alpha) {}
};

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
    Color color = {max_color_val, max_color_val, max_color_val, max_color_val};
    static constexpr unsigned max_color_val = std::numeric_limits<unsigned char>::max();
};
