add_library(board STATIC src/board.cpp)

target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(board PUBLIC drawable blocks)
