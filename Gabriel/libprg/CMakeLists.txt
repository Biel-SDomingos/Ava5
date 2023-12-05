cmake_minimum_required(VERSION 3.26)
project(Gabriel C)

set(CMAKE_C_STANDARD 17)

add_executable(Gabriel main.c
        tabela_hash.c
        lista_encadeada.c
        tabela_hash.h
        lista_encadeada.h)
