#pragma once
#include <list>
#include <utility>

#include "block.hpp"

class TShape : public Block {
   public:
    explicit TShape();
    explicit TShape(const TShape &t) = default;
    TShape &operator=(const TShape &t) = default;
    explicit TShape(TShape &&t) = default;
    TShape &operator=(TShape &&t) noexcept = default;
    ~TShape() override = default;
};