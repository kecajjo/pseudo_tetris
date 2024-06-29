add_library(drawable STATIC
    src/drawable.cpp
)
target_include_directories(drawable PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)