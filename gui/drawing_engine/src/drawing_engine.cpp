#include "drawing_engine.hpp"

#include <memory>

DrawingEngine::DrawingEngine(const unsigned int& height, const unsigned int& width)
    : fb{FrameBuffer(height, width), FrameBuffer(height, width)}, width(width), height(height) {}

void DrawingEngine::display() {
    drawFrameBuffer();
    swapFrameBuffer();
}

void DrawingEngine::swapFrameBuffer() { currentFb = (currentFb + 1) % 2; }

std::optional<Color> DrawingEngine::getPixel(const unsigned int& x, const unsigned int& y) const {
    return fb.at(currentFb).getPixel(x, y);
}

std::optional<Color> DrawingEngine::getPixel(const Drawable::Position& p) const {
    return getPixel(p.x, p.y);
}

void DrawingEngine::setPixel(const Color& c, const unsigned int& x, const unsigned int& y) {
    fb.at(currentFb).setPixel(x, y, c);
}

void DrawingEngine::setPixel(const Color& c, const Drawable::Position& p) { setPixel(c, p.x, p.y); }

void DrawingEngine::drawDrawable(const std::shared_ptr<Drawable>& drawable,
                                 const Drawable::Position& p) {
    auto color = drawable->getColor();
    auto shape = drawable->getShape();
    for (const auto& relativePos : shape) {
        auto pos = relativePos + p;
        setPixel(color, pos);
    }
    for (const auto& [childDrawable, relativePosition] : drawable->getChildDrawables()) {
        Drawable::Position childPos = relativePosition + p;
        drawDrawable(childDrawable, childPos);
    }
}
