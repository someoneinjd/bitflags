cmake_minimum_required(VERSION 3.14)
project(
    bitflags
    VERSION 0.1.0
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

if(PROJECT_IS_TOP_LEVEL)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

add_library(sc_bitflags INTERFACE)
add_library(sc::bitflags ALIAS sc_bitflags)
target_compile_features(
    sc_bitflags
    INTERFACE cxx_std_20
)
target_include_directories(
    sc_bitflags ${warning_guard}
    INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

if(PROJECT_IS_TOP_LEVEL)
    include(CTest)
    if(BUILD_TESTING)
        add_subdirectory(tests)
    endif()
endif()
