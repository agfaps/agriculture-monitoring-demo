cmake_minimum_required(VERSION 3.15)

project(StatusLedUnitTest LANGUAGES CXX)

add_executable(StatusLedTests test_StatusLed.cpp)

target_link_libraries(StatusLedTests PRIVATE gtest_gmock_lib)

enable_testing()

add_test(NAME MyUnitTests COMMAND StatusLedTests)