#pragma once

#include <list>
#include <utility>

#include "drawable.hpp"

class Block : public Drawable {
   public:
    explicit Block(const Block &b) = default;
    Block &operator=(const Block &b) = default;
    explicit Block(Block &&b) = default;
    Block &operator=(Block &&d) noexcept = default;
    ~Block() override = default;

   protected:
    explicit Block() = default;
};