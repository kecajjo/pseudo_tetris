#include <block.hpp>
#include <iostream>
#include "square.hpp"
#include "diagonal.hpp"
#include "lshape.hpp"
#include "tshape.hpp"

#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<Block>> v;
    v.push_back(std::make_unique<Diagonal>());
    v.push_back(std::make_unique<Square>());
    v.push_back(std::make_unique<LShape>());
    v.push_back(std::make_unique<TShape>());
    for (auto &s : v){
        for(auto &p : s->getShape()){
            std::cout << p.x << " " << p.y <<", ";
        }
        std::cout << std::endl;
    }
}