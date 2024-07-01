#include "board.hpp"

void Board::addBlock(std::shared_ptr<Block> blck, Drawable::Position p)
{
    blocks.insert(blck);
    addChild(blck, p);
}