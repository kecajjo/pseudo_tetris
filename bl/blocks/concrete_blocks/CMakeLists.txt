add_library(concrete_blocks STATIC src/square.cpp src/diagonal.cpp
                                   src/lshape.cpp src/tshape.cpp)

target_include_directories(concrete_blocks
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(concrete_blocks PUBLIC block)
