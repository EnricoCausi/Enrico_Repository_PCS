cmake_minimum_required(VERSION 3.20)
project(esercitazione10) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

# Creo il target per l'eseguibile principale del mio progetto software
add_executable(eseguibile gc_mio.cpp)

target_include_directories(eseguibile PRIVATE /usr/include/eigen3)