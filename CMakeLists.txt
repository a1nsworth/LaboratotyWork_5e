cmake_minimum_required(VERSION 3.21)
project(laba5e C)

set(CMAKE_C_STANDARD 11)

add_executable(laba5e main.c)
add_executable(Test tests.c)

add_subdirectory(libs)

target_link_libraries(laba5e libs)
target_link_libraries(Test libs)