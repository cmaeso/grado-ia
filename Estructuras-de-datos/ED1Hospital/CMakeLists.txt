cmake_minimum_required(VERSION 3.25)
project(ED1Hospital C)

set(CMAKE_C_STANDARD 11)

add_executable(ED1Hospital main.c hospital.h hospital.c)
