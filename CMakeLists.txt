cmake_minimum_required(VERSION 3.0)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs")
add_subdirectory(include/cpp-jwt)

add_executable(main main.cpp)
target_link_libraries(main cpp-jwt::cpp-jwt)
