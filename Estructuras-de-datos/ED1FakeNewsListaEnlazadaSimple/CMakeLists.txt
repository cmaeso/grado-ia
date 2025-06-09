cmake_minimum_required(VERSION 3.25)
project(ED1FakeNews C)

set(CMAKE_C_STANDARD 11)

add_executable(ED1FakeNews main.c fakenews.c fakenews.h listaEnlazadaSimple.h listaEnlazadaSimple.c )
