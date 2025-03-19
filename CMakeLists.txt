cmake_minimum_required(VERSION 3.0)
project(test)

option(test "test testJWT function" ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")
add_subdirectory(cpp-jwt)

add_executable(main main.cpp)
target_link_libraries(main cpp-jwt::cpp-jwt)

target_include_directories(main PRIVATE include)
target_compile_definitions(
  main PRIVATE
  $<$<BOOL:${test}>:testJWT>
)

enable_testing()
add_test(NAME main COMMAND $<TARGET_FILE:main>)

add_executable(server_a server_autorization.cpp)
target_link_libraries(server_a cpp-jwt::cpp-jwt)

add_executable(server_b server_game_creator.cpp)
target_link_libraries(server_b cpp-jwt::cpp-jwt)
