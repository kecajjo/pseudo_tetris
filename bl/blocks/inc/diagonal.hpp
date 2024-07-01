#pragma once
#include <list>
#include <utility>

#include "block.hpp"

class Diagonal : public Block {
   public:
    explicit Diagonal();
    explicit Diagonal(const Diagonal &d) = default;
    explicit Diagonal(Diagonal &&d) = default;
    ~Diagonal() override = default;
};