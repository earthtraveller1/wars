find_path(
    GLFW_INCLUDE_DIR
    NAMES "GLFW/glfw3.h"
    PATHS "${CMAKE_SOURCE_DIR}/deps/GLFW/include"
)

if (MSVC)
    if (USE_STATIC_LIBS)
        find_library(
            GLFW_LIBRARY
            NAMES "glfw3.lib"
            PATHS "${CMAKE_SOURCE_DIR}/deps/GLFW/lib" "${CMAKE_SOURCE_DIR}/deps/GLFW/bin"
                  "${CMAKE_SOURCE_DIR}/deps/GLFW/src" "${CMAKE_SOURCE_DIR}/deps/GLFW/build/src"
        )
    else()
        find_library(
            GLFW_LIBRARY
            NAMES "glfw3dll.lib" "glfw3.lib"
            PATHS "${CMAKE_SOURCE_DIR}/deps/GLFW/lib" "${CMAKE_SOURCE_DIR}/deps/GLFW/bin"
                  "${CMAKE_SOURCE_DIR}/deps/GLFW/src" "${CMAKE_SOURCE_DIR}/deps/GLFW/build/src"
        )
    endif()
else()
    if (WIN32)
        if (USE_STATIC_LIBS)
            find_library(
                GLFW_LIBRARY
                NAMES "libglfw3.a"
                PATHS "${CMAKE_SOURCE_DIR}/deps/GLFW/lib" "${CMAKE_SOURCE_DIR}/deps/GLFW/bin"
                      "${CMAKE_SOURCE_DIR}/deps/GLFW/src" "${CMAKE_SOURCE_DIR}/deps/GLFW/build/src"
            )
        else()
            find_library(
                GLFW_LIBRARY
                NAMES "libglfw3dll.a" "libglfw3.a"
                PATHS "${CMAKE_SOURCE_DIR}/deps/GLFW/lib" "${CMAKE_SOURCE_DIR}/deps/GLFW/bin"
                      "${CMAKE_SOURCE_DIR}/deps/GLFW/src" "${CMAKE_SOURCE_DIR}/deps/GLFW/build/src"
            )
        endif()
    else()
        if (USE_STATIC_LIBS)
            find_library(
                GLFW_LIBRARY
                NAMES "libglfw3.a"
                PATHS "${CMAKE_SOURCE_DIR}/deps/GLFW/lib" "${CMAKE_SOURCE_DIR}/deps/GLFW/bin"
                      "${CMAKE_SOURCE_DIR}/deps/GLFW/src" "${CMAKE_SOURCE_DIR}/deps/GLFW/build/src"
            )
        else()
            find_library(
                GLFW_LIBRARY
                NAMES "libglfw.so.3" "libglfw3.a"
                PATHS "${CMAKE_SOURCE_DIR}/deps/GLFW/lib" "${CMAKE_SOURCE_DIR}/deps/GLFW/bin"
                      "${CMAKE_SOURCE_DIR}/deps/GLFW/src" "${CMAKE_SOURCE_DIR}/deps/GLFW/build/src"
            )
        endif()
    endif()
endif()

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args("GLFW" DEFAULT_MSG GLFW_LIBRARY GLFW_INCLUDE_DIR)