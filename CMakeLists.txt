cmake_minimum_required(VERSION 3.29)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 20)

add_executable(Minesweeper main.cpp
        Game.cpp
        Game.h
        Field.cpp
        Field.h
        Player.cpp
        Player.h
        utils.cpp
        utils.h
        Constanter.cpp
        Constanter.h)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(Minesweeper ${CURSES_LIBRARIES})

