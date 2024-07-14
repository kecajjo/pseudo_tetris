#include "block_factory.hpp"

#include <memory>

#include "diagonal.hpp"
#include "lshape.hpp"
#include "square.hpp"
#include "tshape.hpp"

std::unique_ptr<Block> BlockFactory::createBlock(BlockType type) {
    switch (type) {
        case BlockType::DIAGONAL:
            return std::make_unique<Diagonal>();
            break;
        case BlockType::LSHAPE:
            return std::make_unique<LShape>();
            break;
        case BlockType::TSHAPE:
            return std::make_unique<TShape>();
            break;
        case BlockType::SQUARE:
            return std::make_unique<Square>();
            break;
        default:
            return nullptr;
    }
}