cmake_minimum_required(VERSION 3.20)
project(Sort)

add_compile_options(-g -pedantic -Wall -Wextra -std=c++17)

add_library(alg algorithms.cpp populate.cpp timer.cpp)

add_executable(sort main.cpp)
target_link_libraries(sort PUBLIC alg)