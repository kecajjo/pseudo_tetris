#pragma once

#include <array>

#include "drawable.hpp"
#include "frame_buffer.hpp"

class DrawingEngine {
   protected:
    DrawingEngine(const unsigned int& height, const unsigned int& width);

   public:
    virtual ~DrawingEngine() = default;
    explicit DrawingEngine(const DrawingEngine& d) = delete;
    DrawingEngine& operator=(const DrawingEngine& d) = delete;
    explicit DrawingEngine(DrawingEngine&& d) = delete;
    DrawingEngine& operator=(DrawingEngine&& d) noexcept = delete;
    void display();
    void drawDrawable(const std::shared_ptr<Drawable>& drawable, const Drawable::Position& p);

   protected:
    virtual void drawFrameBuffer() const = 0;
    [[nodiscard]] std::optional<Color> getPixel(const unsigned int& x, const unsigned int& y) const;
    [[nodiscard]] std::optional<Color> getPixel(const Drawable::Position& p) const;
    [[nodiscard]] unsigned int getWidth() const { return width; }
    [[nodiscard]] unsigned int getHeight() const { return height; }

   private:
    void swapFrameBuffer();
    void setPixel(const Color& c, const unsigned int& x, const unsigned int& y);
    void setPixel(const Color& c, const Drawable::Position& p);

    std::array<FrameBuffer, 2> fb;
    unsigned int currentFb = 0;
    unsigned int width, height;
};
