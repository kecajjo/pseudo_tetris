add_library(drawing_engine STATIC src/drawing_engine.cpp)
target_include_directories(drawing_engine
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(drawing_engine PRIVATE frame_buffer drawable)
