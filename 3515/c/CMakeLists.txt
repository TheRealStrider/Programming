cmake_minimum_required(VERSION 3.29)
project(c C)

set(CMAKE_C_STANDARD 23)

add_executable(c main.c)
add_executable(AHPA3 AHPA3/ahpa3.c)
add_executable(MultiArray testing/multi-array.c)