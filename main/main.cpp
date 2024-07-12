#include <block.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "diagonal.hpp"
#include "lshape.hpp"
#include "square.hpp"
#include "tshape.hpp"

int main() {
    std::vector<std::unique_ptr<Block>> v;
    v.push_back(std::make_unique<Diagonal>());
    v.push_back(std::make_unique<Square>());
    v.push_back(std::make_unique<LShape>());
    v.push_back(std::make_unique<TShape>());
    for (auto &s : v) {
        for (auto &p : s->getShape()) {
            std::cout << p.x << " " << p.y << ", ";
        }
        std::cout << std::endl;
    }
}