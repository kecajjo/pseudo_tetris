#include "cli_color.hpp"

#include <cstdint>
#include <stdexcept>

#include "color.hpp"
#include "drawing_engine.hpp"
#include "ncursesw/curses.h"

namespace {
constexpr unsigned int colors_nb = 8;
void setupColors() {
    // NOLINTBEGIN
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(7, COLOR_CYAN, COLOR_CYAN);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);
    // NOLINTEND
}
constexpr unsigned int colorToColorPair(const Color& c) {
    uint8_t average = (static_cast<unsigned int>(c.r) + static_cast<unsigned int>(c.g) +
                       static_cast<unsigned int>(c.b) + static_cast<unsigned int>(c.a)) /
                      4;
    uint8_t interval = (std::numeric_limits<unsigned char>::max() + 1) / colors_nb;
    unsigned int color = average / interval + 1;
    return color;
}

}  // namespace

CliColor::CliColor(const unsigned int& height, const unsigned int& width)
    : DrawingEngine(height, width) {
    initscr();
    if (!has_colors()) {
        throw std::runtime_error("Terminal doesnt support colors");
    }
    start_color();
    setupColors();
}

CliColor::~CliColor() { endwin(); }

void CliColor::drawFrameBuffer() const {
    unsigned int height = getHeight();
    unsigned int width = getWidth();
    cbreak();
    noecho();
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            if (auto color = getPixel(x, y)) {
                attron(COLOR_PAIR(colorToColorPair(*color)));
                mvaddstr(y, x * 2, "  ");
            } else {
                throw std::runtime_error("Frame buffer corrupted");
            }
        }
        attron(COLOR_PAIR(0));
    }
    // cursor displays as white, so we move it to the next line
    mvaddstr(height, 0, " ");
    refresh();
}
