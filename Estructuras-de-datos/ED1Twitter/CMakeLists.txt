cmake_minimum_required(VERSION 3.25)
project(ED1Twitter C)

set(CMAKE_C_STANDARD 11)

add_executable(ED1Twitter main.c tweets.h tweets.c )
