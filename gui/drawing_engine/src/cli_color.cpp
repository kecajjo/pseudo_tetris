#include "cli_color.hpp"

#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>

#include "color.hpp"

namespace {
constexpr std::array color_boxes_lookup_table = {"\033[1;47;40m  ",    // black
                                                 "\033[1;47;100m  ",   // bblack
                                                 "\033[1;47;42m  ",    // green
                                                 "\033[1;47;102m  ",   // bgreen
                                                 "\033[1;47;44m  ",    // blue
                                                 "\033[1;47;104m  ",   // bblue
                                                 "\033[1;47;46m  ",    // cyan
                                                 "\033[1;47;106m  ",   // bcyan
                                                 "\033[1;47;41m  ",    // red
                                                 "\033[1;47;101m  ",   // bred
                                                 "\033[1;47;43m  ",    // yellow
                                                 "\033[1;47;103m  ",   // byellow
                                                 "\033[1;47;45m  ",    // magenta
                                                 "\033[1;47;105m  ",   // bmagenta
                                                 "\033[1;47;47m  ",    // white
                                                 "\033[1;47;107m  "};  // bwhite

std::string_view colorToTerminalPixel(const Color& c) {
    uint8_t average = (c.r + c.g + c.b + c.a) / 4;
    uint8_t interval = std::numeric_limits<unsigned char>::max() / color_boxes_lookup_table.size();
    unsigned int color_index = average / interval;
    return color_boxes_lookup_table.at(color_index);
}

}  // namespace

void CliColor::drawFrameBuffer() {
    std::string to_print;
    unsigned int height = getHeight();
    unsigned int width = getWidth();
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            if (auto color = getPixel(x, y)) {
                to_print += colorToTerminalPixel(*color);
            } else {
                throw("Frame buffer corrupted");
            }
        }
        to_print += "\n";
    }
    std::cout << to_print;
}