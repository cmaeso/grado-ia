cmake_minimum_required(VERSION 3.25)
project(ED1VUELOS2 C)

set(CMAKE_C_STANDARD 11)

add_executable(ED1VUELOS2 main.c vuelos.h grafos.h grafos.c vuelos.c)
