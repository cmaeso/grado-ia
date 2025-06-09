cmake_minimum_required(VERSION 3.25)
project(ED1fakenewsLES2P C)

set(CMAKE_C_STANDARD 11)

add_executable(ED1fakenewsLES2P main.c listaEnlazadaPunteroPrinyFin.c fakenews.c)
