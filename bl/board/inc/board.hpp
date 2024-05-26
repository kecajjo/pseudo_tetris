#pragma once

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
        class... Args,
        std::enable_if_t<(
            (is_tuple<Args>::value && ...) &&
            (std::is_same<std::tuple_element<0, Args>, int>::value && ...) &&
            (std::is_convertible<std::tuple_element<2, Args>*, Block*>::value &&
             ...))>>
    void addBlocks(Args... children) {
        (children.push_back(children), ...);
    }
};