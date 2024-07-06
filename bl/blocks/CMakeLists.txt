add_library(blocks STATIC
   src/square.cpp
   src/diagonal.cpp
   src/lshape.cpp
   src/tshape.cpp
)

target_include_directories(blocks PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(blocks PUBLIC drawable)