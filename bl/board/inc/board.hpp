#pragma once

#include <type_traits>

#include "block.hpp"
#include "drawable.hpp"

class Board {
   private:
    template <typename>
    struct is_tuple : std::false_type {};
    template <typename pos, typename ptr>
    struct is_tuple<std::tuple<pos, pos, ptr>> : std::true_type {};

   public:
    template <
        class... Args, std::enable_if_t<(is_tuple<Args>::value && ...), bool> = true,
        std::enable_if_t<(std::is_same<std::tuple_element_t<0, Args>, int>::value && ...), bool> =
            true,
        std::enable_if_t<(std::is_convertible<std::tuple_element_t<2, Args>, Block*>::value && ...),
                         bool> = true>
    void addBlocks(Args... blck) {
        (blocks.push_back(blck), ...);


    private:
    std::list<std::shared_ptr<Block>> blocks;
    }
};