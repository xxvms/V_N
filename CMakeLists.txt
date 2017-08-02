cmake_minimum_required(VERSION 3.8)
project(V_N)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Book.cpp Book.h Library.cpp Library.h Person.cpp Person.h Person.cpp Person.h)
add_executable(V_N ${SOURCE_FILES} Person.cpp Person.h)