#include "block.hpp"

#include <time.h>

#include <cstdlib>

Block::Block() {
    srand(time(NULL));
    this->color = 'a' + rand() % 26;
}
