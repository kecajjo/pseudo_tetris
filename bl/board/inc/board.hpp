#pragma once

#include <type_traits>
#include <unordered_set>

#include "block.hpp"
#include "drawable.hpp"

// TODO rest of the class
class Board : public Drawable {
   private:
    template <typename>
    struct is_tuple : std::false_type {};
    template <typename pos, typename ptr>
    struct is_tuple<std::tuple<pos, pos, ptr>> : std::true_type {};

   public:
    void addBlock(std::shared_ptr<Block> blck, Drawable::Position p) {
        blocks.insert(blck);
        addChild(blck, p);
    }

   private:
    std::unordered_set<std::shared_ptr<Block>> blocks;
};