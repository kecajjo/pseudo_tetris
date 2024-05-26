#pragma once
#include <list>
#include <utility>

#include "block.hpp"

class Square : public Block {
   public:
    explicit Square() {}
    std::list<std::pair<int, int>> getShape() const override;
    ~Square() = default;
};