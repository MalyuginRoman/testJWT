cmake_minimum_required(VERSION 3.0)
project(test)

option(testJWT "test testJWT function" ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")

set(INCLUDE_FILES
    jwt-cpp/jwt.hpp
)

add_executable(testJWT testJWT.cpp)
target_include_directories(testJWT PRIVATE include)
target_compile_definitions(
  testJWT PRIVATE
  $<$<BOOL:${testJWT}>:testJWT>
)

enable_testing()
add_test(NAME testJWT COMMAND $<TARGET_FILE:testJWT>)
