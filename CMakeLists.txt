cmake_minimum_required(VERSION 3.23)
project(Tetris)

set(TIDY
    ON
    CACHE BOOL "Turn clang-tidy on/off")

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -g")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Curses REQUIRED)

if(${TIDY})
  find_program(CLANG_TIDY NAMES "clang-tidy-18" REQUIRED)
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy-18" "-format-style='file'"
                           "-header-filter=.")
endif()

add_subdirectory(bl)
add_subdirectory(gui)

add_executable(tetris main/main.cpp)
target_link_libraries(tetris PUBLIC bl ui)
