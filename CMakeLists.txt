cmake_minimum_required(VERSION 3.17)
project(24010316140048 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(24010316140048
        boolean.h
        mSLLC.c
        SLLC.c
        SLLC.h)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
