cmake_minimum_required(VERSION 3.28)

project(Osim_SixDof LANGUAGES CXX)

find_package(Eigen3 REQUIRED NO_MODULE)

add_subdirectory(apposim)
add_subdirectory(libplanetmodel)
add_subdirectory(librigidbody)
