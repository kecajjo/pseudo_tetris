#pragma once
#include <list>
#include <utility>

#include "block.hpp"

class Square : public Block {
   public:
    explicit Square();
    explicit Square(const Square &s) = default;
    Square &operator=(const Square &s) = default;
    explicit Square(Square &&s) = default;
    Square &operator=(Square &&s) noexcept = default;
    ~Square() override = default;
};