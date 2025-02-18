cmake_minimum_required(VERSION 3.15)

project(gtest_gmock_lib LANGUAGES CXX)

set(GTEST_GMOCK_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/test_src/gtest-all.cc
    # ${CMAKE_CURRENT_SOURCE_DIR}/test_src/gtest_main.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/mock_src/gmock-all.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/mock_src/gmock_main.cc  # Similar with gtest_main.cc, but also sets up Google Mock
)

add_library(
    gtest_gmock_lib
    ${GTEST_GMOCK_SOURCES}
)

target_include_directories(
    gtest_gmock_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gtest
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gmock 
)

# Set C++ standard (C++17 or later)
set_target_properties(gtest_gmock_lib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)


