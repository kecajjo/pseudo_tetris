#pragma once
#include <list>
#include <utility>

#include "block.hpp"

class Diagonal : public Block {
   public:
    explicit Diagonal() {}
    std::list<std::pair<int, int>> getShape() const override;
    ~Diagonal() = default;
};