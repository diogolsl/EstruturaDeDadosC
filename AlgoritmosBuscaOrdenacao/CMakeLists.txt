cmake_minimum_required(VERSION 4.3)
project(AlgoritmosBuscaOrdenacao C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgoritmosBuscaOrdenacao selection_sort.c)
add_executable(AlgoritmosBuscaOrdenacao bubble_sort.c)
add_executable(AlgoritmosBuscaOrdenacao busca_linear.c)
add_executable(AlgoritmosBuscaOrdenacao busca_binaria.c)