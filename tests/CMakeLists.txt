cmake_minimum_required(VERSION 3.14)

include(FetchContent)
FetchContent_Declare(
    boost_ut
    GIT_REPOSITORY https://github.com/boost-ext/ut.git
    GIT_TAG        v2.0.0
    OVERRIDE_FIND_PACKAGE
)

project(bitflags_test LANGUAGES CXX)
find_package(boost_ut REQUIRED)
add_executable(bitflags_test test.cpp)
target_link_libraries(bitflags_test PRIVATE sc::bitflags Boost::ut)
target_compile_features(bitflags_test PRIVATE cxx_std_20)
add_test(
    NAME bitflags_test
    COMMAND bitflags_test
)
