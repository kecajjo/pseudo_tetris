#pragma once
#include <list>
#include <utility>

#include "block.hpp"

class LShape : public Block {
   public:
    explicit LShape();
    explicit LShape(const LShape &l) = default;
    explicit LShape(LShape &&l) = default;
    ~LShape() override = default;
};