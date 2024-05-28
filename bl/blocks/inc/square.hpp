#pragma once
#include <list>
#include <utility>

#include "block.hpp"

class Square : public Block {
   public:
    explicit Square();
    explicit Square(const Square &s) = default;
    explicit Square(Square &&s) = default;
    ~Square() override = default;
};