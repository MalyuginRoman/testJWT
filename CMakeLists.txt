cmake_minimum_required(VERSION 3.0)
project(test)

option(testJWT "test testJWT function" ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")

add_executable(main main.cpp)
target_include_directories(main PRIVATE include)
target_compile_definitions(
  main PRIVATE
  $<$<BOOL:${testJWT}>:testJWT>
)

enable_testing()
add_test(NAME main COMMAND $<TARGET_FILE:main>)
