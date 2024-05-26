#pragma once
#include <list>
#include <utility>

#include "block.hpp"

class TShape : public Block {
   public:
    explicit TShape() {}
    std::list<std::pair<int, int>> getShape() const override;
    ~TShape() = default;
};