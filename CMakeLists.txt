cmake_minimum_required(VERSION 3.7.2)
include("../common.cmake")

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(jwt VERSION ${PROJECT_VERSION})

find_package(jwt-cpp CONFIG REQUIRED)
configure_file(version.h.in version.h)

add_executable(jwt_cli main.cpp)
target_link_libraries(jwt PUBLIC jwt-cpp::jwt-cpp)
add_library(jwt lib.cpp)

set_target_properties(jwt_cli jwt PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(jwt
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(jwt_cli PRIVATE
    mnist_fashion
)

if (MSVC)
    target_compile_options(jwt_cli PRIVATE
        /W4
    )
    target_compile_options(jwt PRIVATE
        /W4
    )
else ()
    target_compile_options(jwt_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(jwt PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS jwt_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
