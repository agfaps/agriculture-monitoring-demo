cmake_minimum_required(VERSION 3.15)

project(UnitTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gmock
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gtest
)

# Add individual module tests
add_subdirectory(StatusLed)
# add_subdirectory(CharDisplay)
