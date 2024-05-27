#pragma once

#include <list>
#include <memory>
#include <tuple>
#include <utility>

class Drawable {
   public:
    virtual ~Drawable() = default;
    virtual char getColor() const = 0;
    virtual std::list<std::pair<int, int>> getShape() const = 0;

    /*!
        Returns list of all children of the object that can be visualised
        tuple: position_x, position_y, ptr_to_child_element
    */
    virtual std::list<std::tuple<int, int, std::shared_ptr<Drawable>>>
    getChildDrawables() const {
        return std::list<std::tuple<int, int, std::shared_ptr<Drawable>>>();
    }
};
