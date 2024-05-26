#pragma once

#include <list>
#include <utility>

#include "drawable.hpp"

class Block : public Drawable {
   private:
    char color;

   public:
    explicit Block();
    explicit Block(const Block &b);
    Block &operator=(const Block &b);  // not virtual, derived class will have
                                       // the same as base one

    // move constructor and move assignment operator not needed, because only
    // static variables
    // explicit Block(Block &&b);
    // Block &operator=(Block &&b);
    char getColor() const override { return color; }

    // virtual std::list<std::pair<int, int>> getShape() const  = 0;
    virtual ~Block() = default;
};