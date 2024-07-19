add_library(cli_color STATIC src/cli_color.cpp)
target_include_directories(cli_color PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(
  cli_color
  PUBLIC drawing_engine
  PRIVATE Curses::Curses)
