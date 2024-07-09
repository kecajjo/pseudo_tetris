#pragma once

#include <unordered_set>

#include "block.hpp"
#include "drawable.hpp"

// TODO rest of the class
class Board : public Drawable {
   public:
    void addBlock(const std::shared_ptr<Block> &blck, Drawable::Position p);

   private:
    std::unordered_set<std::shared_ptr<Block>> blocks;
};