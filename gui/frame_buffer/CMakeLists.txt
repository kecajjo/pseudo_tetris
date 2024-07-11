add_library(frame_buffer STATIC src/frame_buffer.cpp)
target_link_libraries(frame_buffer PUBLIC color)
target_include_directories(frame_buffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
