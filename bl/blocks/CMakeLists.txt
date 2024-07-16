add_subdirectory(concrete_blocks)
add_subdirectory(block_factory)

add_library(block INTERFACE)

target_include_directories(block INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(block INTERFACE drawable)
