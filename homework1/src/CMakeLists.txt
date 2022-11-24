cmake_minimum_required(VERSION 3.15)
project(quadratic_solver)

set(CMAKE_CXX_STANDARD 11)

add_library(${PROJECT_NAME} quadratic_solver.cpp quadratic_solver.h)