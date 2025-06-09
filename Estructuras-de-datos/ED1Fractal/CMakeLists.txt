cmake_minimum_required(VERSION 3.25)
project(ED1fractal C)

set(CMAKE_C_STANDARD 11)

add_executable(ED1fractal main.c Bitmap.h Bitmap.c colourScale.h complejos.h complejos.c circuito.h circuito.c main1.c)
