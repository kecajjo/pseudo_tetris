#include "board.hpp"

void Board::addBlock(const std::shared_ptr<Block> &blck, Drawable::Position p) {
    blocks.insert(blck);
    addChild(blck, p);
}