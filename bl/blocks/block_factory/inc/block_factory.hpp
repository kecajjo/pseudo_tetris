#pragma once

#include <memory>

#include "block.hpp"

enum class BlockType { DIAGONAL, LSHAPE, TSHAPE, SQUARE };

class BlockFactory {
   public:
    BlockFactory() = delete;
    static std::unique_ptr<Block> createBlock(BlockType type);
};