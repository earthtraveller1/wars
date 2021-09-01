cmake_minimum_required(VERSION 3.16)

project("Wars")

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-pedantic")
endif()

add_executable("wars")

add_subdirectory("src")
add_subdirectory("include")