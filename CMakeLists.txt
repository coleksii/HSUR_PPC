cmake_minimum_required(VERSION 3.8)
project(Rush00)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp NLO.cpp NLO.hpp Window.cpp Window.hpp Spaceship.cpp Spaceship.hpp TListNode.hpp TLists.hpp Bullet.cpp Bullet.hpp Game.cpp Game.hpp Enemy.cpp Enemy.hpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

find_package(Curses REQUIRED)
include_directories(Rush00 ${CURSES_INCLUDE_DIR})

add_executable(Rush00 ${SOURCE_FILES})
target_link_libraries(Rush00 ${CURSES_LIBRARIES})
