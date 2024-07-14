add_subdirectory(blocks)
add_subdirectory(board)

add_library(bl INTERFACE)
target_link_libraries(bl INTERFACE board block block_factory)