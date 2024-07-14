add_library(block_factory STATIC src/block_factory.cpp)

target_include_directories(block_factory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(
  block_factory
  PUBLIC block
  PRIVATE concrete_blocks)
