#pragma once
#include <list>
#include <utility>

#include "block.hpp"

class LShape : public Block {
   public:
    explicit LShape() {}
    std::list<std::pair<int, int>> getShape() const override;
    ~LShape() = default;
};