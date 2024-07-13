add_subdirectory(color)
add_subdirectory(drawable)
add_subdirectory(frame_buffer)
add_subdirectory(drawing_engine)

add_library(ui INTERFACE)
target_link_libraries(ui INTERFACE drawing_engine drawable)
