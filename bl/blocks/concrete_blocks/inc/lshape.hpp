#pragma once
#include <list>
#include <utility>

#include "block.hpp"

class LShape : public Block {
   public:
    explicit LShape();
    explicit LShape(const LShape &l) = default;
    LShape &operator=(const LShape &l) = default;
    explicit LShape(LShape &&l) = default;
    LShape &operator=(LShape &&l) noexcept = default;
    ~LShape() override = default;
};