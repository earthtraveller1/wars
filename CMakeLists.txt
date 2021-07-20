cmake_minimum_required(VERSION 3.16)

project("Wars")

option(BUILD_SHARED_LIBS "Whether or not to build shared libraries." OFF)
option(USE_STATIC_LIBS "Wether or not to prefer static libraries over shared ones." OFF)

if (USE_STATIC_LIBS AND NOT MSVC)
    add_link_options("-static")
endif()

include_directories("include")

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall")
endif()

add_executable("wars")
add_library("glad")

add_subdirectory("src")
add_subdirectory("include")

target_link_libraries("wars" "glad")