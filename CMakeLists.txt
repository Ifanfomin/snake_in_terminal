cmake_minimum_required(VERSION 3.10.0)
project(terminal_snake VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(terminal_snake main.cpp)
target_link_libraries(terminal_snake ${CURSES_LIBRARIES})
