cmake_minimum_required(VERSION 3.6)
project(tetris_simple)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

add_subdirectory(bl)

add_executable(tetris main/main.cpp)
target_link_libraries(tetris PUBLIC 
    blocks
    board
)