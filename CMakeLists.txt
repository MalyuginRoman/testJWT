set(CERT_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/rsa_256")
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -DCERT_ROOT_DIR=\"\\\"${CERT_ROOT_DIR}\\\"\"")

add_executable(simple_ex1 simple_ex1.cc)
target_link_libraries(simple_ex1 ${PROJECT_NAME})
add_test(
  NAME simple_ex1
  COMMAND ./simple_ex1
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
