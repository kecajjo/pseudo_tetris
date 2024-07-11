#include "frame_buffer.hpp"

FrameBuffer::FrameBuffer(const unsigned int &height, const unsigned int &width)
    : height(height), width(width) {
    // NOLINTBEGIN
    pixels = new Color *[height];
    for (unsigned int i = 0; i < height; i++) {
        pixels[i] = new Color[width];
    }
    // NOLINTEND
}

FrameBuffer::~FrameBuffer() {
    // NOLINTBEGIN
    if (!pixels) return;
    for (unsigned int i = 0; i < height; i++) {
        delete[] pixels[i];
    }
    delete[] pixels;
    // NOLINTEND
}

std::optional<Color> FrameBuffer::getPixel(const unsigned int &x, const unsigned int &y) const {
    if (x < width && y < height) {
        // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
        return pixels[y][x];
    }
    return {};
}

void FrameBuffer::setPixel(const unsigned int &x, const unsigned int &y, const Color &c) {
    if (x < width && y < height) {
        // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
        pixels[y][x] = c;
    }
}
