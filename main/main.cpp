#include "block.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include "block_factory.hpp"


int main() {
    std::vector<std::unique_ptr<Block>> v;
    v.push_back(BlockFactory::createBlock(BlockType::DIAGONAL));
    v.push_back(BlockFactory::createBlock(BlockType::LSHAPE));
    v.push_back(BlockFactory::createBlock(BlockType::TSHAPE));
    v.push_back(BlockFactory::createBlock(BlockType::SQUARE));
    for (auto &s : v) {
        for (auto &p : s->getShape()) {
            std::cout << p.x << " " << p.y << ", ";
        }
        std::cout << std::endl;
    }
}