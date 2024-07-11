#pragma once

#include <cstdint>

struct Color {
    uint8_t r, g, b, a;
    Color() : r(0), g(0), b(0), a(0) {}
    Color(const uint8_t& red, const uint8_t& green, const uint8_t& blue, const uint8_t& alpha)
        : r(red), g(green), b(blue), a(alpha) {}
};