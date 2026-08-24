cmake_minimum_required(VERSION 4.3)
project(Matrizes C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(Matrizes
        src/main.c
        src/vetor.c
        src/matriz.c)
