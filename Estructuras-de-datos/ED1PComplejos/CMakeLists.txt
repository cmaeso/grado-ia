cmake_minimum_required(VERSION 3.25)
project(ED1PComplejos C)

set(CMAKE_C_STANDARD 11)

add_executable(ED1PComplejos main.c complejos.c complejos.h Bitmap.c Bitmap.h colourScale.h)
