#pragma once

#include <optional>

#include "color.hpp"

class FrameBuffer {
   public:
    explicit FrameBuffer(const unsigned int& height, const unsigned int& width);
    ~FrameBuffer();
    FrameBuffer(const FrameBuffer&) = delete;
    FrameBuffer& operator=(const FrameBuffer&) = delete;
    explicit FrameBuffer(FrameBuffer&& f) = delete;
    FrameBuffer& operator=(FrameBuffer&& f) = delete;
    [[nodiscard]] unsigned int getWidth() const;
    [[nodiscard]] unsigned int getHeight() const;
    [[nodiscard]] std::optional<Color> getPixel(const unsigned int& x, const unsigned int& y) const;
    void setPixel(const unsigned int& x, const unsigned int& y, const Color& c);

   private:
    const unsigned int height, width;
    Color** pixels;
};