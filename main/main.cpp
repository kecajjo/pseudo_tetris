#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <vector>

#include "block.hpp"
#include "block_factory.hpp"
#include "board.hpp"
#include "cli_color.hpp"
#include "drawing_engine.hpp"
// NOLINTBEGIN
constexpr int height = 20;
constexpr int width = 30;
constexpr int xx = 2;
constexpr int yy = 2;
constexpr int sleepsec = 2;

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
    std::shared_ptr<Board> b = std::make_shared<Board>();
    Drawable::Position p{0, 0};
    for (auto &s : v) {
        b->addBlock(std::move(s), p);
        p = p + Drawable::Position{xx, yy};
    }
    std::shared_ptr<DrawingEngine> de = std::make_shared<CliColor>(height, width);
    de->drawDrawable(b, {0, 0});
    de->display();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
// NOLINTEND
